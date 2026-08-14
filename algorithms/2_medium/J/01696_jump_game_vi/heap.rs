use std::collections::BinaryHeap;

impl Solution {
    pub fn max_result(nums: Vec<i32>, k: i32) -> i32 {
        assert!(nums.len() >= 1 && nums.len() <= 100_000 && k >= 1);

        if nums.len() == 1 || k == 1 {
            return nums.iter().sum();
        }

        let len = nums.len() as u32;
        let k = k as u32;
        let mut heap = BinaryHeap::with_capacity(len as usize);
        heap.push((nums[0], 0));
        let mut dp_i = nums[0];

        for i in 1..len {
            let start = if i >= k { i - k } else { 0 };

            while let Some(top) = heap.peek() && top.1 < start {
                heap.pop();
            }

            dp_i = nums[i as usize] + heap.peek().unwrap().0;
            heap.push((dp_i, i));
        }

        dp_i
    }
}
