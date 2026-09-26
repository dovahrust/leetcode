impl Solution {
    pub fn longest_nice_substring(s: String) -> String {
        assert!(s.len() <= 100);

        let bytes = s.as_bytes();
        let len = bytes.len();
        let mut longest: Option<(usize, usize)> = None;

        for i in 0..len {
            let mut cnt_not_nice: usize = 0;
            let mut states = [(false, false); 26];
            for j in i..len {
                let byte = bytes[j];
                match bytes[j] {
                    b'a'..=b'z' => {
                        if !states[(byte - b'a') as usize].1 {
                            states[(byte - b'a') as usize].1 = true;
                            if states[(byte - b'a') as usize].0 {
                                cnt_not_nice -= 1;
                            } else {
                                cnt_not_nice += 1;
                            }
                        }
                    },
                    b'A'..=b'Z' => {
                        if !states[(byte - b'A') as usize].0 {
                            states[(byte - b'A') as usize].0 = true;
                            if states[(byte - b'A') as usize].1 {
                                cnt_not_nice -= 1;
                            } else {
                                cnt_not_nice += 1;
                            }
                        }
                    },
                    _ => unreachable!(),
                }

                if cnt_not_nice == 0 {
                    longest = match longest {
                        None => Some((i, j)),
                        Some((oi, oj)) => {
                            if j - i > oj - oi {
                                Some((i, j))
                            } else {
                                Some((oi, oj))
                            }
                        }
                    }
                }
            }
        }

        match longest {
            None => "".to_string(),
            Some((i, j)) => String::from_utf8_lossy(&bytes[i..=j]).into_owned(),
        }
    }
}
