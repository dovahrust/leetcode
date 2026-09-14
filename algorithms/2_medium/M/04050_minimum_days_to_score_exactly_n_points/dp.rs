impl Solution {
    pub fn min_days(n: i32) -> i32 {
        assert!(n >= 1 && n <= 100_000);
        const RESET_COST: i32 = 1;
        let mut width: i32 = 1;
        let mut width_cost: i32 = 1;
        let mut dp = vec![i32::MAX; (n + 1) as usize];
        dp[0] = 0;

        while width <= n {
            dp[width as usize] = width_cost;

            for i in (width + 1)..=n {
                dp[i as usize] = dp[i as usize].min(dp[(i - width) as usize] + width_cost + RESET_COST);
            }

            width_cost += 1;
            width += width_cost;
        }

        dp[n as usize]
    }
}
