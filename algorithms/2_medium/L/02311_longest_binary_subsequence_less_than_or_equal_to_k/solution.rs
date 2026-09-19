impl Solution {
    pub fn longest_subsequence(s: String, k: i32) -> i32 {
        assert!(k >= 1);
        let k = k as u64;
        let bytes = s.as_bytes();
        let len = bytes.len();
        let mut leading_zeros: usize = 0;
        let mut res: usize = 0;

        for i in 0..len {
            match bytes[i] {
                b'0' => {
                    leading_zeros += 1;
                    res = res.max(leading_zeros);
                },
                b'1' => {
                    let mut curr: u64 = 0;
                    let mut cnt: usize = 0;
                    for &b in &bytes[i..] {
                        let next = (curr << 1) + (b - b'0') as u64;
                        if next > k {
                            break;
                        }
                        curr = next;
                        cnt += 1;
                    }
                    res = res.max(leading_zeros + cnt);
                },
                _ => unreachable!()
            }
        }

        res.try_into().unwrap()
    }
}
