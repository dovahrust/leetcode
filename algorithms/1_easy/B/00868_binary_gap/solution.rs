impl Solution {
    pub fn binary_gap(n: i32) -> i32 {
        let mut n = n as u32;
        while n > 0 && (n & 1) != 1 {
            n >>= 1;
        }

        let mut cnt: i32 = 0;
        let mut max: i32 = 0;

        while n > 1 {
            if (n & 1) == 1 {
                cnt = 1;
            } else {
                cnt += 1;
            }

            max = max.max(cnt);
            n >>= 1;
        }

        max
    }
}
