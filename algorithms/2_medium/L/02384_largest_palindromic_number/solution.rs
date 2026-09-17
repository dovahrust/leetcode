impl Solution {
    pub fn largest_palindromic(num: String) -> String {
        assert!(!num.is_empty());

        let mut freqs = [0_usize; 10];
        for &byte in num.as_bytes() {
            match byte {
                b'0'..=b'9' => freqs[(byte - b'0') as usize] += 1,
                _ => unreachable!(),
            }
        }

        let max_non_zeros: usize = *freqs[1..].iter().max().unwrap();

        match max_non_zeros {
            0 => {
                return "0".to_string();
            },
            1 => {
                for i in (1..10).rev() {
                    if freqs[i] != 0 {
                        return format!("{}", i);
                    }
                }
                unreachable!();
            },
            _ => {
                let res_len: usize = 1 + freqs.iter().map(|&x| if (x & 1) == 1 { x - 1 } else { x }).sum::<usize>();
                let mut res: Vec<u8> = Vec::with_capacity(res_len);
                let mut mid: Option<u8> = None;
                for i in (0..10).rev() {
                    let curr_byte = (i as u8) + b'0';
                    if mid.is_none() && (freqs[i] & 1) == 1 {
                        mid = Some(curr_byte);
                    }

                    let half = freqs[i] / 2;
                    for _ in 0..half {
                        res.push(curr_byte);
                    }
                }

                if let Some(byte) = mid {
                    res.push(byte);
                }

                for i in 0..10 {
                    let curr_byte = (i as u8) + b'0';

                    let half = freqs[i] / 2;
                    for _ in 0..half {
                        res.push(curr_byte);
                    }
                }

                return String::from_utf8(res).unwrap();
            }
        }
    }
}
