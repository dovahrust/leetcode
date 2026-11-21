impl Solution {
    fn dfs(nums: &[i32], idx: usize, memo: &mut [Option<i64>]) -> i64 {
        let len = nums.len();
        
        if len == idx { return 0; }

        if idx + 1 == len { return nums[idx] as i64; }

        if let Some(val) = memo[idx] { return val; }

        let sum1 = nums[idx] as i64;
        let sum2 = (nums[idx] as i64) + (nums[idx + 1] as i64);
        let score1 = if sum1 % 3 == 0 { sum1 - Self::dfs(nums, idx + 1, memo) } else { sum1 + Self::dfs(nums, idx + 1, memo) };
        let score2 = if sum2 % 3 == 0 { sum2 - Self::dfs(nums, idx + 2, memo) } else { sum2 + Self::dfs(nums, idx + 2, memo) };

        let res = score1.max(score2);
        memo[idx] = Some(res);
        
        res
    }

    pub fn max_difference(nums: Vec<i32>) -> i64 {
        let mut memo: Vec<Option<i64>> = vec![None; nums.len()];
        Self::dfs(&nums, 0, &mut memo)
    }
}
