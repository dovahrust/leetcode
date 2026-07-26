impl Solution {
    pub fn matrix_sum(mut nums: Vec<Vec<i32>>) -> i32 {
        let rows = nums.len();
        let cols = nums[0].len();
        let mut score = 0_i32;

        for i in 0..rows {
            nums[i].sort_unstable();
        }

        for j in 0..cols {
            let mut max = i32::MIN;

            for i in 0..rows {
                max = max.max(nums[i][j]);
            }

            score += max;
        }

        score
    }
}
