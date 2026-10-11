impl Solution {
    pub fn min_insertions(s: String) -> i32 {
        let mut balance: isize = 0;
        let mut needs: isize = 0;

        for &b in s.as_bytes() {
            match b {
                b'(' => {
                    if (balance & 1) == 1 {
                        needs += 1;
                        balance += 1;
                    } else {
                        balance += 2;
                    }
                },
                b')' => {
                    if balance == 0 {
                        balance = 1;
                        needs += 1;
                    } else {
                        balance -= 1;
                    }
                },
                _ => {
                    unreachable!()
                },
            }
        }

        (needs + balance).try_into().unwrap()
    }
}
