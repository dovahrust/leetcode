impl Solution {
    #[inline(always)]
    fn get_letters(byte: u8) -> &'static [u8] {
        match byte {
            b'2' => b"abc",
            b'3' => b"def",
            b'4' => b"ghi",
            b'5' => b"jkl",
            b'6' => b"mno",
            b'7' => b"pqrs",
            b'8' => b"tuv",
            b'9' => b"wxyz",
            _ => unreachable!(),
        }
    }

    fn backtrack(
        digits: &[u8],
        idx: usize,
        tmp: &mut Vec<u8>,
        res: &mut Vec<String>, 
    ) {
        let digits_len = digits.len();
        if idx == digits_len {
            res.push(String::from_utf8_lossy(&tmp).into_owned());
            return;
        }

        for &byte in Self::get_letters(digits[idx]) {
            tmp.push(byte);
            Self::backtrack(digits, idx + 1, tmp, res);
            tmp.pop();
        }

    }

    pub fn letter_combinations(digits: String) -> Vec<String> {
        if digits.is_empty() { return Vec::new(); }

        let mut tmp: Vec<u8> = Vec::with_capacity(digits.len());
        let mut res: Vec<String> = Vec::new();

        Self::backtrack(digits.as_bytes(), 0, &mut tmp, &mut res);

        res
    }
}
