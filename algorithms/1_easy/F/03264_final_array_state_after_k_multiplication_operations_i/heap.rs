use std::collections::BinaryHeap;
use std::cmp::Reverse;

impl Solution {
    pub fn get_final_state(mut nums: Vec<i32>, k: i32, multiplier: i32) -> Vec<i32> {
        assert!(!nums.is_empty());

        let mut heap: BinaryHeap<Reverse<(i32, usize)>> = nums.iter().enumerate().map(|(i, &v)| Reverse((v, i))).collect();

        for _ in 0..k {
            let Reverse((_, i)) = heap.pop().unwrap();
            nums[i] *= multiplier;
            heap.push(Reverse((nums[i], i)));
        }

        nums
    }
}
