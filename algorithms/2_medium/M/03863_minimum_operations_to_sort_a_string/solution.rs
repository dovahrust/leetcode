impl Solution {
    pub fn min_operations(s: String) -> i32 {
        let bytes = s.as_bytes();
        let len = bytes.len();

        let mut is_sorted = true;
        for i in 1..len {
            if bytes[i - 1] > bytes[i] {
                is_sorted = false;
                break;
            }
        }
        if is_sorted {
            return 0;
        }
        if len == 2 {
            return -1;
        } 

        let mut min = 255_u8;
        let mut min_freq = 0_isize;
        let mut max = 0_u8;
        let mut max_freq = 0_isize;

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

        if bytes[0] == min || bytes[len - 1] == max {
            return 1;
        }

        if max_freq == 1 && min_freq == 1 && bytes[0] == max && bytes[len - 1] == min {
            return 3;
        }

        2
    }
}
