impl Solution {
    pub fn min_merged_integer(nums: Vec<i32>) -> i32 {
        debug_assert!((nums.len() & 1) == 0 && nums.iter().all(|&x| x >= 1 && x <= 1000));
        let mut min: i32 = i32::MAX;
        let n = nums.len();
        for i in (0..n).step_by(2) {
            let mut tmp = nums[i + 1];
            let mut mul: i32 = 1;
            while tmp > 0 {
                mul *= 10;
                tmp /= 10;
            }
            let merg = nums[i] * mul + nums[i + 1];
            min = min.min(merg);
        }

        min
    }
}
