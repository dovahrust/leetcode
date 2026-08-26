impl Solution {
    pub fn shortest_beautiful_substring(s: String, k: i32) -> String {
        assert!(k >= 1);
        let k = k as usize;
        let bytes = s.as_bytes();
        let len = bytes.len();
        let mut lo = 0_usize;
        let mut res: Option<(usize, usize)> = None;
        let mut ones = 0_usize;

        for hi in 0..len {
            if bytes[hi] == b'1' {
                ones += 1;
            }

            while lo <= hi && (ones > k || bytes[lo] == b'0') {
                if bytes[lo] == b'1' {
                    ones -= 1;
                }
                lo += 1;
            }

            if ones == k {
                if hi - lo + 1 == k {
                    return String::from_utf8_lossy(&bytes[lo..=hi]).into_owned();
                }

                res = match res {
                    None => Some((lo, hi)),
                    Some((res_lo, res_hi)) => {
                        let res_width = res_hi - res_lo + 1;
                        let curr_width = hi - lo + 1;

                        if curr_width < res_width {
                            Some((lo, hi))
                        } else if curr_width == res_width && (&bytes[lo..=hi] < &bytes[res_lo..=res_hi]) {
                            Some((lo, hi))
                        } else {
                            Some((res_lo, res_hi))
                        }
                    }
                };

                lo += 1;
                ones -= 1;
            }
        }

        match res {
            None => String::default(),
            Some((res_lo, res_hi)) => String::from_utf8_lossy(&bytes[res_lo..=res_hi]).into_owned(),
        }
    }
}
