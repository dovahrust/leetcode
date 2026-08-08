impl Solution {
    const MOD: i64 = 1_000_000_007;

    #[inline(always)]
    fn is_prime(n: i32) -> bool {
        if n <= 1 {
            return false;
        }
        let sq = n.isqrt();
        for i in 2..=sq {
            if n % i == 0 {
                return false;
            }
        }
        true
    }

    #[inline(always)]
    fn fact_with_mod(n: i64) -> i64 {
        let mut res = 1;
        for i in 2..=n {
            res = (res * i) % Self::MOD;
        }
        res
    }

    pub fn num_prime_arrangements(n: i32) -> i32 {
        let (mut p, mut o) = (0_i64, 0_i64);
        for i in 1..= n {
            if Self::is_prime(i) {
                p += 1;
            } else {
                o += 1;
            }
        }

        let res = Self::fact_with_mod(p) * Self::fact_with_mod(o);

        (res % Self::MOD) as i32
    }
}
