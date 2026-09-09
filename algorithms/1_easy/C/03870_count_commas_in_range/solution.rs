impl Solution {
    pub fn count_commas(n: i32) -> i32 {
        if n < 1000 { return 0; }

        let n = n as i64;
        let mut base: i64 = 999;
        let mut cnt: i64 = 0;

        while base <= n {
            cnt += (n - base);
            base = base * 1000 + 999;
        }

        cnt.try_into().unwrap()
    }
}
