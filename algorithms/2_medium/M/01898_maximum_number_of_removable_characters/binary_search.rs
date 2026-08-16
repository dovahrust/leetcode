impl Solution {
    #[inline(always)]
    fn is_ok(s: &[u8], p: &[u8], can_use: &[bool]) -> bool {
        let (s_len, p_len) = (s.len(), p.len());
        let (mut s_idx, mut p_idx) = (0_usize, 0_usize);
        while s_idx < s_len && p_idx < p_len {
            if can_use[s_idx] && s[s_idx] == p[p_idx] {
                p_idx += 1;
            }

            s_idx += 1;
        }

        p_idx == p_len
    }

    pub fn maximum_removals(s: String, p: String, removable: Vec<i32>) -> i32 {
        let (s_bytes, p_bytes) = (s.as_bytes(), p.as_bytes());
        let (mut lo, mut hi) = (0_isize, removable.len() as isize - 1);
        let mut can_use = vec![true; s.len()];
        while lo <= hi {
            let mid = lo + (hi - lo) / 2;
            can_use.iter_mut().for_each(|x| *x = true);
            for i in 0..=mid {
                can_use[removable[i as usize] as usize] = false;
            }

            if Self::is_ok(s_bytes, p_bytes, &can_use) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        (hi + 1).try_into().unwrap()
    }
}
