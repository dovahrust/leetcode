impl Solution {
    pub fn max_depth_after_split(seq: String) -> Vec<i32> {
        let bytes = seq.as_bytes();
        let mut res: Vec<i32> = vec![0; seq.len()];
        let mut balance: isize = 0;

        for (i, &b) in bytes.iter().enumerate() {
            match b {
                b'(' => {
                    balance += 1;
                    if balance & 1 == 1 {
                        res[i] = 0;
                    } else {
                        res[i] = 1;
                    }
                },
                b')' => {
                    if balance & 1 == 1 {
                        res[i] = 0;
                    } else {
                        res[i] = 1;
                    }
                    balance -= 1;
                },
                _ => unreachable!("invalid input"),
            }
        }

        res
    }
}
