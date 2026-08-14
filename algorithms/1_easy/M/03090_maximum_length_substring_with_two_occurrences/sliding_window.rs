impl Solution {
    pub fn maximum_length_substring(s: String) -> i32 {
        let bytes = s.as_bytes();
        let len = bytes.len();
        let mut freqs = [0_i8; 256];
        let mut lo = 0_usize;
        let mut max = 0_usize;

        for hi in 0..len {
            freqs[bytes[hi] as usize] += 1;

            while freqs[bytes[hi] as usize] > 2 {
                freqs[bytes[lo] as usize] -= 1;
                lo += 1;
            }

            max = max.max(hi + 1 - lo);
        }

        max.try_into().expect("int overflow")
    }
}
