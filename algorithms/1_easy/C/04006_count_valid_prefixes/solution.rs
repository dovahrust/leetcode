impl Solution {
    pub fn count_valid_prefixes(s: String) -> i32 {
        let mut cnt: usize = 0;
        let mut balance: isize = 0;
        for &b in s.as_bytes() {
            match b {
                b'0' => balance -= 1,
                b'1' => balance += 1,
                _ => unreachable!(),
            }

            if balance.abs() <= 1 { cnt += 1; }
        }

        cnt.try_into().unwrap()
    }
}
