impl Solution {
    pub fn are_occurrences_equal(s: String) -> bool {
        let mut freqs = [0_usize; 256];

        for &b in s.as_bytes() {
            freqs[b as usize] += 1;
        }

        if let Some(&val) = freqs.iter().filter(|&&x| x != 0).next() {
            for f in freqs.into_iter().filter(|&x| x != 0) {
                if f != val {
                    return false;
                }
            }
        }

        true
    }
}
