impl Solution {
    pub fn check_zero_ones(s: String) -> bool {
        let (mut lonegst_one, mut longest_zero) = (0_usize, 0_usize);
        let (mut curr_one, mut curr_zero) = (0_usize, 0_usize);

        for &b in s.as_bytes() {
            match b {
                b'0' => {
                    curr_one = 0;
                    curr_zero += 1;
                    longest_zero = longest_zero.max(curr_zero);
                },
                b'1' => {
                    curr_zero = 0;
                    curr_one += 1;
                    lonegst_one = lonegst_one.max(curr_one);
                },
                _ => {
                    curr_zero = 0;
                    curr_one = 0;
                },
            }
        }

        lonegst_one > longest_zero
    }
}
