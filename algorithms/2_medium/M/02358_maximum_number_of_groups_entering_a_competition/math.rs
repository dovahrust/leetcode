impl Solution {
    pub fn maximum_groups(grades: Vec<i32>) -> i32 {
        let len = grades.len();
        let p = (len * 2).isqrt();

        if p * (p + 1) / 2 <= len {
            p.try_into().unwrap()
        } else {
            (p - 1).try_into().unwrap()
        }
    }
}
