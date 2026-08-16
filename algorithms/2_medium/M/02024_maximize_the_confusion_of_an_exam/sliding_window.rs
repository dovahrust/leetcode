impl Solution {
    pub fn max_consecutive_answers(answer_key: String, k: i32) -> i32 {
        let bytes = answer_key.as_bytes();
        assert!(bytes.len() >= 1 && bytes.len() <= 50_000);

        let (mut cnt_t, mut cnt_f) = (0_i32, 0_i32);
        let mut lo = 0_usize;
        let mut max = 0_i32;

        for &b in bytes {
            match b {
                b'T' => cnt_t += 1,
                b'F' => cnt_f += 1,
                _ => unreachable!(),
            }

            while cnt_f > k && cnt_t > k {
                 match bytes[lo] {
                    b'T' => cnt_t -= 1,
                    _ => cnt_f -= 1,
                }
                lo += 1;
            }

            max = max.max(cnt_t + cnt_f);
        }

        max
    }
}
