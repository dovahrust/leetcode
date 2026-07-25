use std::collections::HashMap;

impl Solution {
    pub fn max_freq(s: String, max_letters: i32, min_size: i32, max_size: i32) -> i32 {
        let mut lo = 0_usize;
        let bytes = s.as_bytes();
        let len = bytes.len();
        assert!(len <= 100_000);
        let mut hashmap: HashMap<&[u8], i32> = HashMap::new();
        let min_size = min_size as usize;
        let mut freqs = [0_i32; 26];
        let mut uniques = 0_i32;

        for hi in 0..len {
            assert!(bytes[hi] >= b'a' &&  bytes[hi] <= b'z');
            freqs[(bytes[hi] - b'a') as usize] += 1;
            if freqs[(bytes[hi] - b'a') as usize] == 1 {
                uniques += 1;
            }
            if (hi - lo + 1) > min_size {
                freqs[(bytes[lo] - b'a') as usize] -= 1;
                if freqs[(bytes[lo] - b'a') as usize] == 0 {
                    uniques -= 1;
                }
                lo += 1;
            }

            if (hi - lo + 1) == min_size && uniques <= max_letters {
                *hashmap.entry(&bytes[lo..=hi]).or_insert(0) += 1;
            }
        }

        if hashmap.is_empty() {
            return 0;
        }

        hashmap.into_iter().map(|(_, freq)| freq).max().unwrap()
    }
}
