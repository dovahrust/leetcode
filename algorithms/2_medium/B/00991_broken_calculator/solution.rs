impl Solution {
    pub fn broken_calc(start_value: i32, target: i32) -> i32 {
        let mut cnt = 0_i32;
        let mut mul = 1_i32;

        while start_value * mul < target {
            mul <<= 1;
            cnt += 1;
        }

        let mut diff = start_value * mul - target;

        while diff != 0 {
            cnt += diff / mul;
            diff = diff % mul;
            mul >>= 1;
        }

        cnt
    }
}
