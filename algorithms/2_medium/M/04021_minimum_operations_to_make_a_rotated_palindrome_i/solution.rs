impl Solution {
    pub fn min_operations(s: String) -> i32 {
        let bytes = s.as_bytes();
        let len = bytes.len() as isize;
        let mut min = isize::MAX;

        for i in 0..len {
            let mut lo = i;
            let mut hi = if i == 0 { len - 1 } else { i - 1 };
            let mut score: isize = 0;

            loop {
                let diff = (bytes[lo as usize] as isize - bytes[hi as usize] as isize).abs();
                score += diff.min(26 - diff);

                hi = if hi - 1 == -1 { len - 1 } else { hi - 1};

                if hi == lo { break; }

                lo = if lo + 1 == len { 0 } else { lo + 1 };

                if hi == lo { break; }
            }

            min = min.min(score + i);
        }

        min.try_into().unwrap()
    }
}
