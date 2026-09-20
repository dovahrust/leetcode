impl Solution {
    #[inline(always)]
    fn calc_h_m(b: &[u8]) -> i32 {
        let h = ((b[0] - b'0') as i32) * 10 + (b[1] - b'0') as i32;
        let m = ((b[3] - b'0') as i32) * 10 + (b[4] - b'0') as i32;

        h * 60 + m
    }

    pub fn convert_time(current: String, correct: String) -> i32 {
        let m1 = Self::calc_h_m(current.as_bytes());
        let m2 = Self::calc_h_m(correct.as_bytes());
        const TOTAL: i32 = 24 * 60;

        let dm = (m2 + TOTAL - m1) % TOTAL;

        dm / 60  + (dm % 60) / 15 + (dm % 15) / 5 + (dm % 5)
    }
}
