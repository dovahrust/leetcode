impl Solution {
    #[inline(always)]
    fn is_pal(bytes: &[u8]) -> bool {
        let mut hi = bytes.len() as isize - 1;
        let mut lo = 0_isize;
        while lo < hi {
            if bytes[hi as usize] == bytes[lo as usize] {
                lo += 1;
                hi -= 1;
            } else {
                return false;
            }
        }
        true
    }

    pub fn remove_palindrome_sub(s: String) -> i32 {
        assert!(s.len() != 0);

        if Self::is_pal(s.as_bytes()) {
            return 1;
        }

        2
    }
}
