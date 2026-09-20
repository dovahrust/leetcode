use std::collections::BinaryHeap;

impl Solution {
    pub fn max_kelements(nums: Vec<i32>, k: i32) -> i64 {
        let mut heap: BinaryHeap<i32> = nums.into_iter().collect();
        let mut res: i64 = 0;

        for _ in 0..k {
            let val = heap.pop().unwrap();
            res += val as i64;
            heap.push((val + 2) / 3);
        }

        res
    }
}
