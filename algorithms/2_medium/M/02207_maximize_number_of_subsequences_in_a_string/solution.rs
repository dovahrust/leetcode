impl Solution {
    pub fn maximum_subsequence_count(text: String, pattern: String) -> i64 {
        assert!(pattern.len() == 2);
        let (p1, p2) = (pattern.as_bytes()[0], pattern.as_bytes()[1]);
        let (mut p1_cnt, mut p2_cnt): (i64, i64) = (0, 0);
        let mut res: i64 = 0;

        for &byte in text.as_bytes() {
            if byte == p2 {
                res += p1_cnt;
                p2_cnt += 1;
            }

            if byte == p1 { p1_cnt += 1; }
        }

        res + std::cmp::max(p1_cnt, p2_cnt)
    }
}
