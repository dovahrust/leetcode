impl Solution {
    pub fn min_operations(s: String) -> i32 {
        let bytes = s.as_bytes();
        let len = bytes.len();

        if len <= 1 || bytes.windows(2).all(|w| w[0] <= w[1]) { return 0; }

        if len == 2 { return -1; } 

        let mut min = u8::MAX;
        let mut min_freq: usize = 0;
        let mut max = u8::MIN;
        let mut max_freq: usize = 0;

        for &b in bytes {
            if b < min {
                min = b;
                min_freq = 1;
            } else if b == min {
                min_freq += 1;
            }

            if b > max {
                max = b;
                max_freq = 1;
            } else if b == max {
                max_freq += 1;
            }
        }

        if bytes[0] == min || bytes[len - 1] == max { return 1; }

        if max_freq == 1 && min_freq == 1 && bytes[0] == max && bytes[len - 1] == min { return 3; }

        2
    }
}
