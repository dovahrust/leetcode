impl Solution {
    #[inline(always)]
    fn is_pal(bytes: &[u8]) -> bool {
        if bytes.len() == 0 { return true; }

        let mut lo = 0;
        let mut hi = bytes.len() - 1;

        while lo < hi {
            if bytes[lo] != bytes[hi] {
                return false;
            }

            lo += 1;
            hi -= 1;
        }

        true
    }

    pub fn max_palindromes(s: String, k: i32) -> i32 {
        let bytes = s.as_bytes();
        let k = k as usize;

        if k > bytes.len() { return 0; }

        if k == 1 { return bytes.len().try_into().unwrap(); }

        let len = bytes.len();
        let mut i: usize = 0;
        let mut cnt: usize = 0;

        while i + k <= len {
            if Self::is_pal(&bytes[i..(i + k)]) {
                i += k;
                cnt += 1;
            } else if  i + k + 1 <= len && Self::is_pal(&bytes[i..(i + k + 1)]) {
                i += k + 1;
                cnt += 1;
            } else {
                i += 1;
            }
        }

        cnt.try_into().unwrap()
    }
}
