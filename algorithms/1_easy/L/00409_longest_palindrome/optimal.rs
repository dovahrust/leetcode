impl Solution {
    pub fn longest_palindrome(s: String) -> i32 {
        assert!(s.len() <= 2_000);
        let mut freqs = [0_i16; 256];

        for &byte in s.as_bytes().iter() {
            freqs[byte as usize] += 1;
        }

        let mut cnt = 0_i32;

        for freq in freqs {
            cnt += (freq - (freq & 1)) as i32;
        }

        (cnt + 1).min(s.len() as i32)
    }
}
