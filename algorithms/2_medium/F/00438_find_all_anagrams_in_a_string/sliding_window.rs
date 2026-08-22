impl Solution {
    pub fn find_anagrams(s: String, p: String) -> Vec<i32> {
        if p.len() > s.len() { return Vec::new(); }

        let mut freqs_p = [0_usize; 256];
        for &byte in p.as_bytes() {
            freqs_p[byte as usize] += 1;
        }

        let s_bytes = s.as_bytes();
        let s_len = s_bytes.len();
        let p_len = p.len();
        let mut freqs_window = [0_usize; 256];
        let mut res: Vec<i32> = Vec::new();
        let mut lo = 0_usize;

        for hi in 0..s_len {
            let idx_bytes_hi = s_bytes[hi] as usize;
            freqs_window[idx_bytes_hi] += 1;

            while freqs_window[idx_bytes_hi] > freqs_p[idx_bytes_hi] {
                freqs_window[s_bytes[lo] as usize] -= 1;
                lo += 1;
            }

            if hi - lo + 1 == p_len {
                res.push(lo as i32);
            }
        }

        res
    }
}
