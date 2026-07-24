impl Solution {
    #[inline(always)]
    fn gray_to_bin(mut g: i32) -> i32 {
        let mut res = g;
        while g != 0 {
            g >>= 1;
            res ^= g;
        }
        res
    }

    pub fn circular_permutation(n: i32, start: i32) -> Vec<i32> {
        assert!(n >= 1 && n <= 16);
        let cnt = 2_i32.pow(n as u32);
        let mut res = Vec::with_capacity(cnt as usize);
        let mut curr = Self::gray_to_bin(start);

        for _ in 0..cnt {
            res.push(curr ^ (curr >> 1));
            curr = (curr + 1) % cnt;
        }

        res
    }
}
