use std::cmp::Reverse;
use std::collections::BinaryHeap;

impl Solution {
    const MOD: i64 = 1_000_000_007;

    pub fn maximum_product(nums: Vec<i32>, k: i32) -> i32 {
        assert!(!nums.is_empty());
        if nums.len() == 1 { return (((nums[0] as i64) + k as i64) % Self::MOD) as i32; }

        let mut heap: BinaryHeap<Reverse<i32>> = nums.into_iter().map(|x| Reverse(x)).collect();

        for _ in 0..k {
            let Reverse(val) = heap.pop().unwrap();
            heap.push(Reverse(val + 1));
        }

        let mut res: i64 = 1;
        for Reverse(val) in heap {
            res = (res * val as i64) % Self::MOD;
        }

        res as i32
    }
}
