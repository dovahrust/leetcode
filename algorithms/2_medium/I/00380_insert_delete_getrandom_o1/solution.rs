use std::collections::HashMap;
use rand::Rng;

struct RandomizedSet {
    arr: Vec<i32>,
    map: HashMap<i32, usize>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl RandomizedSet {

    fn new() -> Self {
        Self {
            arr: Vec::new(),
            map: HashMap::new(),
        }
    }

    fn insert(&mut self, val: i32) -> bool {
        if self.map.contains_key(&val) { return false; }

        self.map.insert(val, self.arr.len());
        self.arr.push(val);
        true
    }

    fn remove(&mut self, val: i32) -> bool {
        let Some(del_idx) = self.map.remove(&val) else { return false; };
        let len = self.arr.len();

        if len - 1 != del_idx {
            let move_val = self.arr[len - 1];
            self.arr[del_idx] = move_val;
            self.map.insert(move_val, del_idx);
        }

        self.arr.pop();

        true
    }

    fn get_random(&self) -> i32 {
        let idx = rand::thread_rng().gen_range(0..self.arr.len());
        self.arr[idx]
    }
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * let obj = RandomizedSet::new();
 * let ret_1: bool = obj.insert(val);
 * let ret_2: bool = obj.remove(val);
 * let ret_3: i32 = obj.get_random();
 */
