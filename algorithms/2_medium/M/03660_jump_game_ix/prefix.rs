impl Solution {
    pub fn max_value(nums: Vec<i32>) -> Vec<i32> {
        if nums.is_empty() { return Vec::default(); }
        let len = nums.len();
        let mut prefix = vec![0_i32; len];
        prefix[0] = nums[0];
        for i in 1..len {
            prefix[i] = nums[i].max(prefix[i - 1]);
        }
        let mut curr_min = i32::MAX;
        let mut curr_max = 0;
        for i in (0..len).rev() {
            if prefix[i] > curr_min {
                prefix[i] = curr_max;
                curr_min = curr_min.min(nums[i]);
            } else {
                curr_max = prefix[i];
                curr_min = nums[i];
            }
        }

        prefix
    }
}
