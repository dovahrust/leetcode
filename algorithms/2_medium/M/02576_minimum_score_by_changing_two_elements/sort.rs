impl Solution {
    pub fn minimize_sum(mut nums: Vec<i32>) -> i32 {
        let len = nums.len();
        if len <= 2 { return 0; }

        nums.sort_unstable();
        let c1 = nums[len - 3] - nums[0];
        let c2 = nums[len - 2] - nums[1];
        let c3 = nums[len - 1] - nums[2];

        c1.min(c2).min(c3)
    }
}
