impl Solution {
    pub fn min_add_to_make_valid(s: String) -> i32 {
        let mut res: usize = 0;
        let mut open_cnt: usize = 0;

        for &b in s.as_bytes().iter() {
            match b {
                b'(' => open_cnt += 1,
                b')' => {
                    if open_cnt > 0 {
                        open_cnt -= 1;
                    } else {
                        res += 1;
                    }
                },
                _ => unreachable!()
            }
        }

        (res + open_cnt).try_into().unwrap()
    }
}
