impl Solution {
    fn dfs(idx: usize, stones: &[i32], memo: &mut [i32]) -> i32 {
        let len = stones.len();
        if idx >= len {
            return 0;
        }

        if memo[idx] != i32::MIN {
            return memo[idx];
        }

        let mut res = i32::MIN;
        let mut sum = 0_i32;
        for i in idx..((idx + 3).min(len)) {
            sum += stones[i];
            res = res.max(sum - Self::dfs(i + 1, stones, memo));
        }
        memo[idx] = res;

        res
    }

    pub fn stone_game_iii(stone_value: Vec<i32>) -> String {
        let mut dp = vec![i32::MIN; stone_value.len()];

        match Self::dfs(0, &stone_value, &mut dp).cmp(&0) {
            std::cmp::Ordering::Less => "Bob".to_string(),
            std::cmp::Ordering::Equal => "Tie".to_string(),
            std::cmp::Ordering::Greater => "Alice".to_string(),
        }
    }
}
