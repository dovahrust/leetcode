impl Solution {
    pub fn num_of_subsequences(s: String) -> i64 {
        let mut t: i64 = s.as_bytes().iter().filter(|&&b| b == b'T').count() as i64;
        let mut l: i64 = 0;
        let mut ct: i64 = 0;
        let mut lc: i64 = 0;
        let mut max_l_times_t: i64 = 0;
        let mut res: i64 = 0;

        for &b in s.as_bytes() {
            match b {
                b'T' => {
                    t -= 1;
                },
                b'L' => {
                    l += 1;
                    max_l_times_t = max_l_times_t.max(l * t);
                },
                b'C' => {
                    ct += t;
                    lc += l;
                    res += l * t;
                },
                _ => {}
            }
        }

        res + max_l_times_t.max(ct).max(lc)
    }
}
