impl Solution {
    pub fn count_dominant_elements(nums: Vec<i32>) -> i32 {
        let len = nums.len();
        if len <= 1 { return len as i32; }

        let mut cnt: usize = 0;

        if nums[0] >= nums[1] { cnt += 1; }

        if nums[len - 2] <= nums[len - 1] { cnt += 1; }

        for w in nums.windows(3) {
            if 2 * w[1] >= w[0] + w[2] { cnt += 1; }
        }

        cnt.try_into().unwrap()
    }
}
