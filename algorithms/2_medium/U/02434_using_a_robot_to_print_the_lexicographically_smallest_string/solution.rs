impl Solution {
    #[inline(always)]
    fn update_curr(freqs: &[usize; 26], curr: &mut usize) {
        while *curr < freqs.len() && freqs[*curr] == 0 {
            *curr += 1;
        }
    }

    pub fn robot_with_string(s: String) -> String {
        if s.is_empty() { return String::new(); }

        let bytes = s.as_bytes();
        let mut freqs = [0_usize; 26];
        for &b in bytes {
            freqs[(b - b'a') as usize] += 1;
        }

        let mut curr = 0_usize;
        Self::update_curr(&freqs, &mut curr);
        let mut stack: Vec<u8> = Vec::with_capacity(bytes.len());
        let mut res: Vec<u8> = Vec::with_capacity(bytes.len());
        for &b in bytes {
            let idx_b = (b - b'a') as usize;
            freqs[idx_b] -= 1;
            if idx_b == curr {
                res.push(b);
                if freqs[idx_b] == 0 {
                    Self::update_curr(&freqs, &mut curr);
                    while let Some(&top) = stack.last() {
                        let idx_top = (top - b'a') as usize;
                        if idx_top <= curr {
                            res.push(top);
                            stack.pop();
                        } else {
                            break;
                        }
                    }
                }
            } else {
                stack.push(b);
            }
        }

        String::from_utf8(res).unwrap()
    }
}
