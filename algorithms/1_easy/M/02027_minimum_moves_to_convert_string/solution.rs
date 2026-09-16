impl Solution {
    pub fn minimum_moves(s: String) -> i32 {
        let bytes = s.as_bytes();
        let len = bytes.len();
        let mut idx: usize = 0;
        let mut cnt: usize = 0;

        while idx < len {
            match bytes[idx] {
                b'X' => {
                    idx += 3;
                    cnt += 1;
                },
                b'O' => {
                    idx += 1;
                },
                _ => {
                    unreachable!();
                }
            }
        }

        cnt.try_into().unwrap()
    }
}
