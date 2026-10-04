impl Solution {
    pub fn check_valid_string(s: String) -> bool {
        let mut points: isize = 0;
        let mut balance: isize = 0;

        for &byte in s.as_bytes().iter() {
            match byte {
                b'(' => balance += 1,
                b'*' => points += 1,
                b')' => {
                    balance -= 1;
                    if balance < 0 {
                        if points <= 0 { return false; }

                        points -= 1;
                        balance += 1;
                    }
                },
                _ => unreachable!("invalid input"),
            }
        }

        let mut points: isize = 0;
        let mut balance: isize = 0;

        for &byte in s.as_bytes().iter().rev() {
            match byte {
                b')' => balance += 1,
                b'*' => points += 1,
                b'(' => {
                    balance -= 1;
                    if balance < 0 {
                        if points <= 0 { return false; }

                        points -= 1;
                        balance += 1;
                    }
                },
                _ => unreachable!("invalid input"),
            }
        }

        true
    }
}
