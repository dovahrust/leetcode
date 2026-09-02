impl Solution {
    fn calc_val(bytes: &[u8]) -> u32 {
        let mut res = 0_u32;
        for &b in bytes {
            debug_assert!(b >= b'a' && b <= b'j');
            res = res * 10 + (b - b'a') as u32;
        }
        res
    }

    pub fn is_sum_equal(first_word: String, second_word: String, target_word: String) -> bool {
        assert!(first_word.len() <= 8 && second_word.len() <= 8 && target_word.len() <= 8);

        let f = Self::calc_val(first_word.as_bytes());
        let s = Self::calc_val(second_word.as_bytes());
        let t = Self::calc_val(target_word.as_bytes());

        f + s == t
    }
}
