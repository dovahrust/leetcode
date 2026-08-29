impl Solution {
    pub fn min_deletions(s: String) -> i32 {
        let mut freqs = [0_usize; 256];
        for &b in s.as_bytes() {
            freqs[b as usize] += 1;
        }
        freqs.sort_unstable_by(|a, b| b.cmp(&a));
        let mut cnt = 0_usize;
        let mut prev = freqs[0];
        for f in freqs.into_iter().filter(|&x| x > 0).skip(1) {
            if prev > 0 {
                prev -= 1;
            }

            if f > prev {
                cnt += f - prev;
            }

            prev = prev.min(f);
        }

        cnt.try_into().unwrap()
    }
}
