use std::cell::RefCell;
use std::rc::{Rc, Weak};

struct Node {
    val: i32,
    next: Option<Rc<RefCell<Node>>>,
    prev: Option<Weak<RefCell<Node>>>,
}

impl Node {
    fn new(val: i32) -> Self {
        Self {
            val: val,
            next: None,
            prev: None,
        }
    }
}

struct MyLinkedList {
    len: usize,
    head: Option<Rc<RefCell<Node>>>,
    tail: Option<Rc<RefCell<Node>>>,
}

impl MyLinkedList {
    #[inline(always)]
    fn get_kth_from_begin(&self, k: usize) -> Rc<RefCell<Node>> {
        let mut curr = self.head.as_ref().unwrap().clone();
        for i in 0..k {
            let next = curr.borrow().next.as_ref().unwrap().clone();
            curr = next;
        }
        curr
    }

    #[inline(always)]
    fn get_kth_from_end(&self, k: usize) -> Rc<RefCell<Node>> {
        let mut curr = self.tail.as_ref().unwrap().clone();
        for i in 0..k {
            let next = curr.borrow().prev.as_ref().unwrap().upgrade().unwrap().clone();
            curr = next;
        }
        curr
    }

    fn new() -> Self {
        Self {
            len: 0,
            head: None,
            tail: None,
        }
    }

    fn get(&self, index: i32) -> i32 {
        let from_left = index as usize;
        if (from_left >= self.len) { return -1; }
        let from_right = self.len - 1 - from_left;
        let curr = if from_left <= from_right { self.get_kth_from_begin(from_left) } else { self.get_kth_from_end(from_right) };
        curr.borrow().val
    }

    fn add_at_head(&mut self, val: i32) {
        let mut node = Rc::new(RefCell::new(Node::new(val)));

        match self.head.clone() {
            Some(head_node) => {
                head_node.borrow_mut().prev = Some(Rc::downgrade(&node));
                node.borrow_mut().next = Some(head_node);
                self.head = Some(node);
            },
            None => {
                self.head = Some(node.clone());
                self.tail = Some(node);
            }
        }

        self.len += 1;
    }
    
    fn add_at_tail(&mut self, val: i32) {
        let mut node = Rc::new(RefCell::new(Node::new(val)));

        match self.tail.as_mut() {
            Some(tail_node) => {
                tail_node.borrow_mut().next = Some(node.clone());
                node.borrow_mut().prev = Some(Rc::downgrade(tail_node));
                self.tail = Some(node);
            },
            None => {
                self.head = Some(node.clone());
                self.tail = Some(node);
            }
        }

        self.len += 1;
    }

    fn add_at_index(&mut self, index: i32, val: i32) {
        let from_left = index as usize;
        if (from_left > self.len) { return; }
        let from_right = self.len - 1 - from_left;

        if from_left == 0 {
            self.add_at_head(val);
        } else if from_left == self.len {
            self.add_at_tail(val);
        } else {
            let mut curr = if from_left <= from_right { self.get_kth_from_begin(from_left) } else { self.get_kth_from_end(from_right) };
            let mut node = Rc::new(RefCell::new(Node::new(val)));
            node.borrow_mut().next = Some(curr.clone());
            node.borrow_mut().prev = curr.borrow_mut().prev.take();
            node.borrow().prev.as_ref().unwrap().upgrade().unwrap().borrow_mut().next = Some(node.clone());
            curr.borrow_mut().prev = Some(Rc::downgrade(&node));

            self.len += 1;
        }
    }

    fn delete_at_index(&mut self, index: i32) {
        let from_left = index as usize;
        if from_left >= self.len { return; }
        let from_right = self.len - 1 - from_left;

        if self.len == 1 {
            self.head = None;
            self.tail = None;
            self.len = 0;
        } else if from_left == 0 {
            let next = self.head.as_mut().unwrap().borrow_mut().next.take();
            self.head = next;
            self.head.as_mut().unwrap().borrow_mut().prev = None;
            self.len -= 1;
        } 
        else if (from_right == 0) {
            let prev = self.tail.as_mut().unwrap().borrow_mut().prev.as_ref().unwrap().upgrade().unwrap();
            prev.borrow_mut().next.take();
            self.tail = Some(prev);
            self.len -= 1;
        } else {
            let mut curr = if from_left <= from_right { self.get_kth_from_begin(from_left) } else { self.get_kth_from_end(from_right) };
            let mut next = curr.borrow_mut().next.take();
            let mut prev = curr.borrow_mut().prev.take().unwrap().upgrade().unwrap();
            next.as_mut().unwrap().borrow_mut().prev = Some(Rc::downgrade(&prev));
            prev.borrow_mut().next = next;
            self.len -= 1;
        }
    }
}
