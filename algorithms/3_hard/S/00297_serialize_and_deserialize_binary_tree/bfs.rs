// Definition for a binary tree node.
// #[derive(Debug, PartialEq, Eq)]
// pub struct TreeNode {
//   pub val: i32,
//   pub left: Option<Rc<RefCell<TreeNode>>>,
//   pub right: Option<Rc<RefCell<TreeNode>>>,
// }
// 
// impl TreeNode {
//   #[inline]
//   pub fn new(val: i32) -> Self {
//     TreeNode {
//       val,
//       left: None,
//       right: None
//     }
//   }
// }
use std::rc::Rc;
use std::cell::RefCell;
use std::collections::VecDeque;
struct Codec {
	
}

/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Codec {
    fn new() -> Self {
        Self {}
    }

    #[inline(always)]
    fn push_val_to_buff(buff: &mut Vec<u8>, val: i32) {
        if val == 0 {
            buff.push(b'0');
        } else {
            if val < 0 {
                buff.push(b'-');
            }

            let mut abs_val = (val as i64).abs();
            let mut digs = [0_u8; 20];
            let mut digs_len = 0_usize;
            while abs_val > 0 {
                digs[digs_len] = b'0' + (abs_val % 10) as u8;
                digs_len += 1;
                abs_val /= 10; 
            }

            while digs_len > 0 {
                digs_len -= 1;
                buff.push(digs[digs_len]);
            }
        }
    }

    fn serialize(&self, root: Option<Rc<RefCell<TreeNode>>>) -> String {
        if root.is_none() {
            return "#".to_string();
        }

        let mut buff: Vec<u8> = Vec::new();
        let mut q: VecDeque<Option<Rc<RefCell<TreeNode>>>> = VecDeque::new();

        q.push_back(root); 
        while let Some(node_rc_opt) = q.pop_front() {
            if let Some(node_rc) = node_rc_opt{
                let node = node_rc.borrow();
                Self::push_val_to_buff(&mut buff, node.val);
                buff.push(b' ');
                q.push_back(node.left.clone());
                q.push_back(node.right.clone());
            } else {
                buff.push(b'#');
                buff.push(b' ');
            }
        }

        String::from_utf8(buff).unwrap()
    }

    fn deserialize(&self, data: String) -> Option<Rc<RefCell<TreeNode>>> {
        if data.as_str() == "#" {
            return None;
        }

        let mut dummy = Rc::new(RefCell::new(TreeNode::new(-1)));
        let mut q: VecDeque<(Rc<RefCell<TreeNode>>, bool)> = VecDeque::new();
        q.push_back((dummy.clone(), true));
        for part in data.split_whitespace() {
            if part == "#" {
                let (_, left_used) = q.front_mut().expect("queue can be empty");
                if ! (*left_used) {
                    *left_used = true;
                } else {
                    q.pop_front();
                }
            } else {
                let val = part.parse::<i32>().unwrap();
                let node = Rc::new(RefCell::new(TreeNode::new(val)));
                let (parent, left_used) = q.front_mut().expect("queue can be empty");
                if ! (*left_used) {
                    *left_used = true;
                    parent.borrow_mut().left = Some(node.clone());
                } else {
                    parent.borrow_mut().right = Some(node.clone());
                    q.pop_front();
                }
                q.push_back((node, false));
            }
        }

        dummy.borrow_mut().right.take()
    }
}

/**
 * Your Codec object will be instantiated and called as such:
 * let obj = Codec::new();
 * let data: String = obj.serialize(strs);
 * let ans: Option<Rc<RefCell<TreeNode>>> = obj.deserialize(data);
 */
