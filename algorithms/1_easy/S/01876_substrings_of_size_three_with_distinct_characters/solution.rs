impl Solution {
    pub fn count_good_substrings(s: String) -> i32 {
        let mut cnt = 0_usize;

        for w in s.as_bytes().windows(3) {
            if w[0] != w[1] && w[0] != w[2] && w[1] != w[2] {
                cnt += 1;
            }
        }

        cnt.try_into().unwrap()
    }
}
