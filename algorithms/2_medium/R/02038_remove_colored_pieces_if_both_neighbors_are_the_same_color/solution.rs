impl Solution {
    pub fn winner_of_game(colors: String) -> bool {
        if colors.len() <= 2 { return false; }

        let bytes = colors.as_bytes();
        let len = bytes.len();
        let mut a = 0_usize;
        let mut b = 0_usize;

        for i in 1..(len - 1) {
            if bytes[i - 1] == bytes[i] && bytes[i] == bytes[i + 1] {
                match bytes[i] {
                    b'A' => a += 1,
                    b'B' => b += 1,
                    _ => unreachable!(),
                }
            }
        }

        a > b
    }
}
