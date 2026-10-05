impl Solution {
    pub fn min_rotations(s: String) -> i32 {
        let mut prev: i32 = 0;
        let mut res: i32 = 0;

        for &b in s.as_bytes() {
            let curr = (b - b'0') as i32;
            let diff = (prev - curr).abs();
            res += std::cmp::min(diff, 10 - diff);
            prev = curr;
        }

        res
    }
}
