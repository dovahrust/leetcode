impl Solution {
    pub fn num_splits(s: String) -> i32 {
        if s.len() <= 1 { return 0; }

        let bytes = s.as_bytes();

        let mut cnt_right = 0_i32;
        let mut freqs_right = [0_usize; 256];
        for &b in bytes {
            if freqs_right[b as usize] == 0 {
                cnt_right += 1;
            }
            freqs_right[b as usize] += 1;
        }

        let mut freqs_left = [0_usize; 256];
        let mut cnt_left = 0_i32;

        let mut res = 0_usize;
        for &b in bytes {
            if cnt_left == cnt_right {
                res += 1;
            }

            freqs_right[b as usize] -= 1;
            if freqs_right[b as usize] == 0 {
                cnt_right -= 1;
            }

            if freqs_left[b as usize] == 0 {
                cnt_left += 1;
            }
            freqs_left[b as usize] += 1;
        }

        res.try_into().unwrap()
    }
}
