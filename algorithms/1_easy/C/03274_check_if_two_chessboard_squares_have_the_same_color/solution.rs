impl Solution {
    #[inline(always)]
    fn calc_color(b: &[u8])-> u8 {
        ((b[0] - b'0') + (b[1] - b'a')) & 1
    }

    pub fn check_two_chessboards(coordinate1: String, coordinate2: String) -> bool {
        Self::calc_color(coordinate1.as_bytes()) == Self::calc_color(coordinate2.as_bytes()) 
    }
}
