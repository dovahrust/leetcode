use std::collections::HashMap;

const INVALID_IDX: usize = usize::MAX;

struct Node {
    key: i32,
    val: i32,
    next: usize,
    prev: usize,
}

struct LRUCache {
    cap: usize,
    ll: Vec<Node>,
    hashmap: HashMap<i32, usize>,
    head: usize,
    tail: usize,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl LRUCache {
    #[inline(always)]
    fn move_node_to_head(&mut self, node_idx: usize) {
        if node_idx == self.head { return; }

        let prev_idx = self.ll[node_idx].prev;
        let next_idx = self.ll[node_idx].next;

        self.ll[node_idx].next = self.head;
        self.ll[node_idx].prev = INVALID_IDX;

        self.ll[self.head].prev = node_idx;
        self.head = node_idx;

        self.ll[prev_idx].next = next_idx;
        if next_idx == INVALID_IDX {
            self.tail = prev_idx;
        } else {
            self.ll[next_idx].prev = prev_idx;
        }
    }

    fn new(cap: i32) -> Self {
        assert!(cap > 0);
        Self {
            cap: cap as usize,
            ll: Vec::with_capacity(cap as usize),
            hashmap: HashMap::new(),
            head: INVALID_IDX,
            tail: INVALID_IDX,
        }
    }
    
    fn get(&mut self, key: i32) -> i32 {
        if let Some(&node_idx) = self.hashmap.get(&key) {
            self.move_node_to_head(node_idx);
            return self.ll[node_idx].val;
        }
        -1
    }
    
    fn put(&mut self, key: i32, val: i32) {
        if let Some(&node_idx) = self.hashmap.get(&key) {
            self.ll[node_idx].val = val;
            self.move_node_to_head(node_idx);
        } else if self.ll.len() == self.cap {
            let tail_idx = self.tail;
            let old_tail_key = self.ll[tail_idx].key;
            self.hashmap.remove(&old_tail_key);
            self.hashmap.insert(key, tail_idx);
            self.ll[tail_idx].val = val;
            self.ll[tail_idx].key = key;
            self.move_node_to_head(tail_idx);
        } else {
            let new_node_idx = self.ll.len();
            self.ll.push(Node { key: key, val: val, prev: INVALID_IDX, next: self.head });
            if self.head == INVALID_IDX {
                self.head = new_node_idx;
                self.tail = new_node_idx;
            } else {
                self.ll[self.head].prev = new_node_idx;
                self.head = new_node_idx;
            }
            self.hashmap.insert(key, new_node_idx);
        }
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * let obj = LRUCache::new(capacity);
 * let ret_1: i32 = obj.get(key);
 * obj.put(key, value);
 */
