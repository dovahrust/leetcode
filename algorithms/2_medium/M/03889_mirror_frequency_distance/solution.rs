impl Solution {
    #[inline(always)]
    fn calc_range(freqs: &[isize], lo: usize, hi: usize) -> isize {
        let half = ((hi - lo + 1) >> 1);
        let mut res: isize = 0;

        for i in 0..half {
            let c = lo + i;
            let m = hi - i;
            res += (freqs[c] - freqs[m]).abs();
        }

        res
    }

    pub fn mirror_frequency(s: String) -> i32 {
        let mut freqs = [0_isize; 256];
        for &b in s.as_bytes() {
            freqs[b as usize] += 1;
        }

        let mut res: isize = Self::calc_range(&freqs, b'a' as usize, b'z' as usize) + 
                             Self::calc_range(&freqs, b'0' as usize, b'9' as usize);

        res.try_into().unwrap()
    }
}
