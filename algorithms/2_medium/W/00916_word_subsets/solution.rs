impl Solution {
    const FREQS_LEN: usize = 26;

    #[inline(always)]
    fn calc_freqs(bytes: &[u8]) -> [u8; Self::FREQS_LEN] {
        assert!(bytes.len() <= u8::MAX as usize);
        let mut res = [0_u8; Self::FREQS_LEN];
        for &b in bytes {
            assert!(b >= b'a' && b <= b'z');
            res[(b - b'a') as usize] += 1;
        }
        res
    }

    pub fn word_subsets(mut words1: Vec<String>, words2: Vec<String>) -> Vec<String> {
        let mut max_freqs2 = [0_u8; Self::FREQS_LEN];
        for w in words2 {
            let freqs = Self::calc_freqs(w.as_bytes());
            for i in 0..Self::FREQS_LEN {
                max_freqs2[i] = max_freqs2[i].max(freqs[i]);
            }
        }
        let mut res: Vec<String> = Vec::new();

        for w in words1{
            let freqs = Self::calc_freqs(w.as_bytes());
            let mut is_valid = true;

            for i in 0..Self::FREQS_LEN {
                if max_freqs2[i] > freqs[i] {
                    is_valid = false;
                    break;
                }
            }

            if is_valid {
                res.push(w);
            }
        }

        res
    }
}
