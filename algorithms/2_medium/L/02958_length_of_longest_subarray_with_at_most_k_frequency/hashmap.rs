use std::collections::HashMap;

impl Solution {
    pub fn max_subarray_length(nums: Vec<i32>, k: i32) -> i32 {
        assert!(k >= 1 && (k as usize) <= nums.len() && nums.len() <= 100_000);
        let k = k as u32;
        let len = nums.len();
        let mut freqs: HashMap<i32, u32> = HashMap::new();
        let mut lo = 0_usize;
        let mut max = 0_usize;
        for hi in 0..len {
            *freqs.entry(nums[hi]).or_insert(0) += 1;
            while freqs[&nums[hi]] > k {
                *freqs.get_mut(&nums[lo]).unwrap() -= 1;
                lo += 1;
            }
            max = max.max(hi - lo + 1);
        }

        max as i32
    }
}
