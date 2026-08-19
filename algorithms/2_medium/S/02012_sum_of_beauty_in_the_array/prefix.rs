impl Solution {
    pub fn sum_of_beauties(nums: Vec<i32>) -> i32 {
        if nums.len() <= 2 { return 0; }

        let len = nums.len();
        let mut min_right = vec![0_i32; len];
        min_right[len - 1] = nums[len - 1];
        for i in (0..(len - 1)).rev() {
            min_right[i] = nums[i].min(min_right[i + 1]);
        }

        let mut res = 0_i32;
        let mut max_left = nums[0];

        for i in 1..(len - 1) {
            if max_left < nums[i] && nums[i] < min_right[i + 1] {
                res += 2;
            } else if nums[i - 1] < nums[i] && nums[i] < nums[i + 1] {
                res += 1;
            }

            max_left = max_left.max(nums[i]);
        }

        res
    }
}
