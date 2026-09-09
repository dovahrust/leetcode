impl Solution {
    pub fn count_commas(n: i64) -> i64 {
        assert!(n >= 1 && n <= 1_000_000_000_000_000);

        if n < 1000 { return 0; }

        let mut base: i64 = 999;
        let mut cnt: i64 = 0;

        while base <= n {
            cnt += (n - base);
            base = base * 1000 + 999;
        }

        cnt
    }
}
