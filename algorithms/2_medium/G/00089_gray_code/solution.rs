impl Solution {
    pub fn gray_code(n: i32) -> Vec<i32> {
        assert!(n >= 1 && n <= 16);
        let len = 1_i32 << n;
        let mut res: Vec<i32> = Vec::with_capacity(len as usize);
        unsafe { res.set_len(len as usize); }

        for i in 0..len {
            res[i as usize] = (i ^ (i >> 1));
        }

        res
    }
}
