impl Solution {
    #[inline(always)]
    fn get_idx(b: u8) -> usize {
        match b {
            b'Q' => 0,
            b'W' => 1,
            b'E' => 2,
            b'R' => 3,
            _ => unreachable!()
        }
    }

    pub fn balanced_string(s: String) -> i32 {
        let bytes = s.as_bytes();
        let len = bytes.len();
        assert!(len % 4 == 0 && len != 0 && len <= 100_000);
        let mut cnt = [0_i32; 4];
        for &b in bytes {
            cnt[Self::get_idx(b)] += 1;
        }
        let mut lo = 0_usize;
        let limit = (len / 4) as i32;
        let mut res = len;

        for hi in 0..len {
            cnt[Self::get_idx(bytes[hi])] -= 1;
            while lo <= hi && cnt[Self::get_idx(bytes[lo])] < limit {
                 cnt[Self::get_idx(bytes[lo])] += 1;
                 lo += 1;
            }

            if cnt.iter().all(|c| *c <= limit) {
                 res = res.min(hi + 1 - lo);
            }
        }

        res.try_into().unwrap()
    }
}
