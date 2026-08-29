impl Solution {
    pub fn count_substrings(s_string: String, t_string: String) -> i32 {
        let (s, t) = (s_string.as_bytes(), t_string.as_bytes());
        let (s_len, t_len) = (s.len() as isize, t.len() as isize);
        let mut cnt = 0_isize;

        for s_idx in 0..s_len {
            for t_idx in 0..t_len {
                if s[s_idx as usize] != t[t_idx as usize] {
                    let mut lo = 1_isize;
                    while s_idx - lo >= 0 && t_idx - lo >= 0 && s[(s_idx - lo) as usize] == t[(t_idx - lo) as usize] {
                        lo += 1;
                    }

                    let mut hi = 1_isize;
                    while s_idx + hi < s_len && t_idx + hi < t_len && s[(s_idx + hi) as usize] == t[(t_idx + hi) as usize] {
                        hi += 1;
                    }

                    cnt += hi * lo;
                }
            }
        }

        cnt.try_into().unwrap()
    }
}
