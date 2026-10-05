impl Solution {
    pub fn min_rotations(n: i32, s: String) -> i32 {
        let last: i32 = (*s.as_bytes().last().unwrap() - b'0') as i32;
        let mut prev: i32 = 0;
        let mut res: i32 = 0;
        let mut max_save: i32 = 0;

        for &b in s.as_bytes() {
            let curr = (b - b'0') as i32;
            let diff = (prev - curr).abs();
            let min_r = std::cmp::min(diff, 10 - diff);
            res += min_r;
            let diff_last = (prev - last).abs();
            let min_r_last = std::cmp::min(diff_last, 10 - diff_last);
            max_save = max_save.max(min_r - min_r_last);
            prev = curr;
        }

        res - max_save
    }
}
