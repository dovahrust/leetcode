impl Solution {
    #[inline(always)]
    fn is_sub(s: &[u8], t: &[u8]) -> bool {
        let (s_len, t_len) = (s.len(), t.len());
        let (mut s_idx, mut t_idx) = (0_usize, 0_usize);

        while s_idx < s_len && t_idx < t_len {
            if s_len - s_idx < t_len - t_idx || s[s_idx] != t[t_idx] { return false; }

            let byte = s[s_idx];
            let (s_begin, t_begin) = (s_idx, t_idx);

            while s_idx < s_len && s[s_idx] == byte {
                s_idx += 1;
            }

            while t_idx < t_len && t[t_idx] == byte {
                t_idx += 1;
            }

            let s_cnt = s_idx - s_begin;
            let t_cnt = t_idx - t_begin;

            if s_cnt != t_cnt && (s_cnt < t_cnt || s_cnt == 2) {
                return false;
            } 
        }

        s_idx == s_len && t_idx == t_len
    }

    pub fn expressive_words(s: String, words: Vec<String>) -> i32 {
        let s_bytes = s.as_bytes();
        let mut cnt = 0_i32;

        for w in words {
            if Self::is_sub(s_bytes, w.as_bytes()) {
                cnt += 1;
            }
        }

        cnt
    }
}
