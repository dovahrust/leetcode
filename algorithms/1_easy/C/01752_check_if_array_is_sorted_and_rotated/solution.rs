impl Solution {
    pub fn check(nums: Vec<i32>) -> bool {
        let len = nums.len();
        assert!(len >= 1);

        let mut hi = len - 1;
        while hi > 0 && nums[hi - 1] <= nums[hi] {
            hi -= 1;
        }

        if hi == 0 {
            return true;
        }

        let mut lo = 0;
        while lo + 1 < len && nums[lo] <= nums[lo + 1] {
            lo += 1;
        }

        lo +  1 == hi && nums[0] >= nums[len - 1]
    }
}
