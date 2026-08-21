impl Solution {
    #[inline(always)]
    fn is_sub(a: &[u8], b: &[u8]) -> bool {
        if a.len() > b.len() { return false; }

        let (a_len, b_len) = (a.len(), b.len());
        let (mut a_idx, mut b_idx) = (0_usize, 0_usize);

        while a_idx < a_len && b_idx < b_len {
            if a[a_idx] == b[b_idx] {
                a_idx += 1;
            }
            b_idx += 1;
        }

        a_len == a_idx
    }

    pub fn find_lu_slength(strs: Vec<String>) -> i32 {
        let len = strs.len();
        assert!(len >= 2);
        let mut res = -1_isize;
        'main_loop: for i in 0..len {
            for j in 0..len {
                if i == j { continue; }

                if Self::is_sub(strs[i].as_bytes(), strs[j].as_bytes()) {
                    continue 'main_loop;
                }
            }

            res = res.max(strs[i].len() as isize);
        }

        res.try_into().unwrap()
    }
}
