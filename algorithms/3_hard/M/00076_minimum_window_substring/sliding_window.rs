impl Solution {
    pub fn min_window(s: String, t: String) -> String {
        if s.is_empty() || t.is_empty() { return String::new(); }

        let s_bytes = s.as_bytes();
        let s_len = s_bytes.len();
        if s_len < t.len() { return String::default(); }
        let mut freqs: [isize; 256] = [0; 256];

        for &byte in t.as_bytes() {
            freqs[byte as usize] -= 1;
        }

        let mut missing_distinct = freqs.iter().filter(|&&x| x != 0).count();
        let mut lo = 0;
        let mut res = &s_bytes[0..0];

        for hi in 0..s_len {
            freqs[s_bytes[hi] as usize] += 1;
            if freqs[s_bytes[hi] as usize] == 0 {
                missing_distinct -= 1;
            }

            while lo <= hi && freqs[s_bytes[lo] as usize] > 0 {
                freqs[s_bytes[lo] as usize] -= 1;
                lo += 1;
            }

            if missing_distinct == 0 && (res.is_empty() || res.len() > (hi + 1 - lo)) {
                res = &s_bytes[lo..=hi];
                // Remove leftmost required char to continue searching for a smaller window
                freqs[s_bytes[lo] as usize] -= 1;
                lo += 1;
                missing_distinct += 1;
            }
        }

        String::from_utf8(res.to_vec()).unwrap()
    }
}
