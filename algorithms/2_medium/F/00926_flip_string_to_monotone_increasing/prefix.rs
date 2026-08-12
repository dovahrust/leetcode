impl Solution {
    pub fn min_flips_mono_incr(s: String) -> i32 {
        assert!(s.len() <= 100_000);
        let mut make_ones = s.as_bytes().into_iter().filter(|&&b| b == b'0').count() as i32;
        let mut make_zeros = 0_i32;
        let mut res = make_ones;

        for &b in s.as_bytes() {
            match b {
                b'0' => {
                    make_ones -= 1;
                },
                b'1' => {
                    make_zeros += 1;
                },
                _ => unreachable!(),
            }

            res = res.min(make_ones + make_zeros);
        }

        res
    }
}
