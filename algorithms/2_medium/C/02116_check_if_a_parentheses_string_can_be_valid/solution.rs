impl Solution {
    #[inline(always)]
    fn is_ok_forward(s: &[u8], l: &[u8]) -> bool {
        let len = s.len();
        let mut balance = 0_isize;

        for i in 0..len {
            match (l[i], s[i]) {
                (b'1', b')') => balance -= 1,
                _ => balance += 1,
            }

            if balance < 0 {
                return false;
            }
        }

        true
    }

    #[inline(always)]
    fn is_ok_backward(s: &[u8], l: &[u8]) -> bool {
        let len = s.len();
        let mut balance = 0_isize;

        for i in (0..len).rev() {
            match (l[i], s[i]) {
                (b'1', b'(') => balance -= 1,
                _ => balance += 1,
            }

            if balance < 0 {
                return false;
            } 
        }

        true
    }

    pub fn can_be_valid(s: String, locked: String) -> bool {
        debug_assert!(s.len() == locked.len() && !s.is_empty());

        if (s.len() & 1) == 1 { return false; }

        Self::is_ok_forward(s.as_bytes(), locked.as_bytes()) &&
        Self::is_ok_backward(s.as_bytes(), locked.as_bytes())
    }
}
