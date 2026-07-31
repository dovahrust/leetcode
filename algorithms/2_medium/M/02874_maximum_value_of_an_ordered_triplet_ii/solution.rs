impl Solution {
    pub fn maximum_triplet_value(nums: Vec<i32>) -> i64 {
        let len = nums.len();
        assert!(len >= 3);
        let mut diff = nums[0] - nums[1];
        let mut max = nums[0].max(nums[1]);
        let mut res = i64::MIN;

        for i in 2..len {
            res = res.max(diff as i64 * nums[i] as i64);
            diff = diff.max(max - nums[i]);
            max = max.max(nums[i]);
        }

        res.max(0)
    }
}
