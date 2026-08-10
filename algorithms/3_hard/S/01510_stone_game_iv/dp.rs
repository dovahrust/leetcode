impl Solution {
    pub fn winner_square_game(n: i32) -> bool {
        assert!(n >= 1 && n <= 100_000);
        let n = n as usize;
        let mut dp = vec![false; n + 1];
        for i in (0..n).rev() {
            let mut j = 1;
            while i + (j * j) <= n {
                if !dp[i + (j * j)] {
                    dp[i] = true;
                    break;
                }
                j += 1;
            }
        }

        dp[0]
    }
}
