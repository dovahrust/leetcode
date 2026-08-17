impl Solution {
    #[inline(always)]
    fn calc_h_m(b: &[u8]) -> i32 {
        let h = ((b[0] - b'0') as i32) * 10 + (b[1] - b'0') as i32;
        let m = ((b[3] - b'0') as i32) * 10 + (b[4] - b'0') as i32;

        h * 60 + m
    }

    pub fn number_of_rounds(login_time: String, logout_time: String) -> i32 {
        let tb = Self::calc_h_m(login_time.as_bytes());
        let te = Self::calc_h_m(logout_time.as_bytes());

        if te >= tb {
            if te < tb + 15 {
                return 0;
            }

            return (te / 15) - ((tb + 14) / 15);
        }

        (te / 15) + ((24 * 60 - tb) / 15)
    }
}
