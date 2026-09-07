impl Solution {
    #[inline(always)]
    fn rev_bits(mut byte: u8) -> u8 {
        let mut rev_byte = 0_u8;

        for _ in 0..u8::BITS {
            rev_byte <<= 1;
            rev_byte |= (byte & 1);
            byte >>= 1;
        }

        rev_byte
    }

    pub fn is_palindromic(s: String) -> bool {
        let bytes = s.as_bytes();
        let len = bytes.len();
        let mut hi = (len as isize) - 1;
        let mut lo = 0_isize;

        while lo <= hi {
            if Self::rev_bits(bytes[lo as usize]) != bytes[hi as usize] {
                return false;
            }
            lo += 1;
            hi -= 1;
        }

        true
    }
}
