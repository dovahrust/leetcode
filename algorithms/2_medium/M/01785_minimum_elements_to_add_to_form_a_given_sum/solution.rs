impl Solution {
    pub fn min_elements(nums: Vec<i32>, limit: i32, goal: i32) -> i32 {
        let (goal, limit) = (goal as i64, limit as i64);
        let sum: i64 = nums.iter().map(|x| *x as i64).sum();
        let diff = (goal - sum).abs();

        ((diff + limit - 1) / limit) as i32
    }
}
