use std::collections::BinaryHeap;

impl Solution {
    pub fn min_stone_sum(piles: Vec<i32>, k: i32) -> i32 {
        let mut heap: BinaryHeap<i32> = piles.into_iter().collect();
        for _ in 0..k {
            let v = heap.pop().unwrap();
            heap.push(v - (v / 2));
        }
        heap.into_iter().sum::<i32>()
    }
}
