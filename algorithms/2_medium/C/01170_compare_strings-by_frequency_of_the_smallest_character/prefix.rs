impl Solution {
    const MAX_ALLOWED_FREQ: usize = 10;

    #[inline(always)]
    fn calc_freqs_smallest_char(bytes: &[u8]) -> usize {
        let mut curr_byte = b'z';
        let mut freq = 0_usize;

        for &b in bytes {
            assert!(b >= b'a' && b <= b'z');
            if b < curr_byte {
                curr_byte = b;
                freq = 1;
            } else if b == curr_byte {
                freq += 1;
            }
        }

        freq
    }

    pub fn num_smaller_by_frequency(queries: Vec<String>, words: Vec<String>) -> Vec<i32> {
        assert!(words.len() <= 2000 && queries.len() <= 2000);
        let mut prefix = [0_i16; Self::MAX_ALLOWED_FREQ + 1];

        for w in words {
            let freq = Self::calc_freqs_smallest_char(w.as_bytes());
            assert!(freq <= Self::MAX_ALLOWED_FREQ);
            prefix[freq] += 1;
        }
        for i in 1..=Self::MAX_ALLOWED_FREQ {
            prefix[i] += prefix[i - 1];
        }

        let mut res: Vec<i32> = Vec::with_capacity(queries.len());
        unsafe { res.set_len(queries.len()); }
        for (i, q) in queries.into_iter().enumerate() {
            let freq = Self::calc_freqs_smallest_char(q.as_bytes());
            if freq >= Self::MAX_ALLOWED_FREQ {
                res[i] = 0;
            } else {
                res[i] = (prefix[Self::MAX_ALLOWED_FREQ] - prefix[freq]) as i32;
            }
        }

        res
    }
}
