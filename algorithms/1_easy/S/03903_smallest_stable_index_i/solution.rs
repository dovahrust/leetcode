impl Solution {
    pub fn first_stable_index(nums: Vec<i32>, k: i32) -> i32 {
        assert!(!nums.is_empty() && k >= 0);
        if nums.len() == 1 { return 0; }

        let len = nums.len();
        let mut mins = nums.clone();
        for i in (0..(len - 1)).rev() {
            mins[i] = mins[i].min(mins[i + 1]);
        }

        let mut max = i32::MIN;
        for i in 0..len {
            max = max.max(nums[i]);
            if max - mins[i] <= k {
                return i as i32;
            }
        }

        -1
    }
}
