impl Solution {
    pub fn shifting_letters(s: String, mut shifts: Vec<i32>) -> String {
        debug_assert!(
            s.len() == shifts.len() &&
            s.len() > 0 &&
            shifts.iter().all(|&x| x >= 0 && x <= 1_000_000_000) &&
            s.as_bytes().iter().all(|&b| b >= b'a' && b <= b'z')
        );

        let mut bytes = s.into_bytes();
        let len = bytes.len();

        shifts[len - 1] %= 26;
        for i in (0..(len - 1)).rev() {
            shifts[i] = (shifts[i] + shifts[i + 1]) % 26;
        }

        for (i, b) in bytes.iter_mut().enumerate() {
            let shift = shifts[i];
            let v = (*b - b'a' + shift as u8) % 26;
            *b = v + b'a';
        }

        String::from_utf8(bytes).unwrap()
    }
}
