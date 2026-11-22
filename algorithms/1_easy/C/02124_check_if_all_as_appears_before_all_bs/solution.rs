impl Solution {
    pub fn check_string(s: String) -> bool {
        let mut seen_b = false;
        for &b in s.as_bytes() {
            if b == b'b' { 
                seen_b = true;
            } else if seen_b {
                return false;
            }
        }

        true
    }
}
