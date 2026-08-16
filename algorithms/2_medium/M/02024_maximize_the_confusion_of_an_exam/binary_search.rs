impl Solution {
    #[inline(always)]
    fn is_ok(prefix: &[(u16, u16)], w: usize, k: i32) -> bool {
        let len = prefix.len();
        let end = len - w;
        for i in 0..end {
            let cnt_t = (prefix[i + w].0 - prefix[i].0) as i32;
            let cnt_f = (prefix[i + w].1 - prefix[i].1) as i32;

            if cnt_t <= k || cnt_f <= k {
                return true;
            }
        }

        false
    }

    pub fn max_consecutive_answers(answer_key: String, k: i32) -> i32 {
        let bytes = answer_key.as_bytes();
        let len = bytes.len();
        assert!(len >= 1 && len <= 50_000);
        let mut prefix = vec![(0_u16, 0_u16); len + 1];
        for (i, &b) in bytes.into_iter().enumerate() {
            prefix[i + 1].0 = prefix[i].0 + if b == b'T' { 1 } else { 0 };
            prefix[i + 1].1 = prefix[i].1 + if b == b'F' { 1 } else { 0 };
        }

        let mut lo = 1_usize;
        let mut hi = len;
        while lo <= hi {
            let mid = lo + (hi - lo) / 2;
            if Self::is_ok(&prefix, mid, k) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }

        }

        hi as i32
    }
}
