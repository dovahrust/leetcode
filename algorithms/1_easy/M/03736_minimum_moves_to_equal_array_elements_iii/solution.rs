impl Solution {
    pub fn min_moves(nums: Vec<i32>) -> i32 {
        let max = *nums.iter().max().unwrap();
        nums.into_iter().map(|v| max - v).sum::<i32>()
    }
}
