use std::collections::VecDeque;

impl Solution {
    pub fn longest_subarray(nums: Vec<i32>, limit: i32) -> i32 {
        let len = nums.len();
        assert!(limit >= 0);
        let mut minq: VecDeque<i32> = VecDeque::new();
        let mut maxq: VecDeque<i32> = VecDeque::new();
        let mut lo = 0_usize;
        let mut res = 0_usize;

        for hi in 0..len {
            let num = nums[hi];
            while let Some(val) = maxq.back() && *val < num {
                maxq.pop_back();
            }
            while let Some(val) = minq.back() && *val > num {
                minq.pop_back();
            }
            maxq.push_back(num);
            minq.push_back(num);

            while limit < (*maxq.front().unwrap() - *minq.front().unwrap()) {
                if *maxq.front().unwrap() == nums[lo] {
                    maxq.pop_front();
                }
                if *minq.front().unwrap() == nums[lo] {
                    minq.pop_front();
                }
                lo += 1;
            }

            res = res.max(hi - lo + 1);
        }

        res.try_into().unwrap()
    }
}
