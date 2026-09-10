impl Solution {
    pub fn max_repeating(sequence: String, word: String) -> i32 {
        let (s, w) = (sequence.as_bytes(), word.as_bytes());
        let (s_len, w_len) = (s.len(), w.len());

        if w_len > s_len || w_len == 0 || s_len == 0 { return 0; }

        let mut dp = vec![0_usize; (s_len - w_len) + 2];

        for i in 0..=(s_len - w_len) {
            if &s[i..(i + w_len)] == w {
                dp[i] = 1 + if i >= w_len { dp[i - w_len] } else { 0 };
            }
        }

        dp.into_iter().max().unwrap().try_into().unwrap()
    }
}
