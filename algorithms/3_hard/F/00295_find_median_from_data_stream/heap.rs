use std::collections::BinaryHeap;
use std::cmp::Reverse;

struct MedianFinder {
    min_heap: BinaryHeap<Reverse<i32>>,
    max_heap: BinaryHeap<i32>
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl MedianFinder {

    fn new() -> Self {
        Self {
            min_heap: BinaryHeap::new(),
            max_heap: BinaryHeap::new(),
        }
    }
    
    fn add_num(&mut self, num: i32) {
        if let Some(Reverse(top_min_ref)) = self.min_heap.peek() && *top_min_ref < num {
            self.min_heap.push(Reverse(num));
            if self.min_heap.len() > self.max_heap.len() + 1 {
                let Reverse(top_min) = self.min_heap.pop().unwrap();
                self.max_heap.push(top_min);
            }
        } else {
            self.max_heap.push(num);
            if self.max_heap.len() > self.min_heap.len() {
                self.min_heap.push(Reverse(self.max_heap.pop().unwrap()));
            }
        }
    }
    
    fn find_median(&self) -> f64 {
        if self.max_heap.len() == self.min_heap.len() {
            let top_max = *self.max_heap.peek().unwrap();
            let Reverse(top_min) = *self.min_heap.peek().unwrap();
            return ((top_max as f64) + (top_min as f64)) / 2.0_f64;
        }

        let Reverse(top_min) = *self.min_heap.peek().unwrap();
        top_min as f64
    }
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * let obj = MedianFinder::new();
 * obj.add_num(num);
 * let ret_2: f64 = obj.find_median();
 */
