impl Solution {
    pub fn min_range(a: i32, b: i32, c: i32) -> i32 {
        let uc = a.max(b).max(c) - a.min(b).min(c);
        let ac = b + c - b.min(c);
        let bc = a + c - a.min(c);
        let cc = a + b - a.min(b);

        uc.min(ac).min(bc).min(cc)
    }
}
