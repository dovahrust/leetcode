impl Solution {
    const MOD: i32 = 1_000_000_007;

    fn dfs(n: i32, k: i32, can_add_to_prev: bool, memo: &mut [[i32; 2]], memo_cols: usize) -> i32 {
        if n <= k { return 0; }

        if k == 0 {
            return if can_add_to_prev { n } else { 0 };
        }

        if n == k + 1 { return 1; }
 
        let memo_idx = (n as usize) * memo_cols + k as usize;
        if  memo[memo_idx][can_add_to_prev as usize] != -1 {
            return memo[memo_idx][can_add_to_prev as usize];
        }

        let mut res: i32 = 0;

        let skip = Self::dfs(n - 1, k, false, memo, memo_cols);
        res = (res + skip) % Self::MOD;
        if can_add_to_prev {
            let keep = Self::dfs(n - 1, k, true, memo, memo_cols);
            res = (res + keep) % Self::MOD;
        }
        let new_st = Self::dfs(n - 1, k - 1, true, memo, memo_cols);
        res = (res + new_st) % Self::MOD;

        memo[memo_idx][can_add_to_prev as usize] = res;
        res
    }

    pub fn number_of_sets(n: i32, k: i32) -> i32 {
        let memo_rows = (n + 1) as usize;
        let memo_cols = (k + 1) as usize;
        let mut memo = vec![[-1_i32, -1_i32]; memo_rows * memo_cols];
        Self::dfs(n, k, false, &mut memo, memo_cols)
    }
}
