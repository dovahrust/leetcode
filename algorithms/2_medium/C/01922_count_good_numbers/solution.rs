impl Solution {
    const MOD: i64 = 1_000_000_007;

    #[inline(always)]
    fn pow_by_mod(mut base: i64, mut expo: i64, mod_by: i64) -> i64 {
        let mut res: i64 = 1;
        while expo > 0 {
            if (expo & 1) == 1 {
                res = (res * base) % mod_by;
            }
            base = (base * base) % mod_by;
            expo >>= 1;
        }
        res
    }

    pub fn count_good_numbers(n: i64) -> i32 {
        assert!(n > 0);

        let half = n / 2;

        let odd = Self::pow_by_mod(4, half, Self::MOD);
        let even = Self::pow_by_mod(5, n - half, Self::MOD);
        let res = (odd * even) % Self::MOD;

        res as i32
    }
}
