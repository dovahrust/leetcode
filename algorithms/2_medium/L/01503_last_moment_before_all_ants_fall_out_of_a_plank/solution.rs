impl Solution {
    pub fn get_last_moment(n: i32, left: Vec<i32>, right: Vec<i32>) -> i32 {
        let mut res = 0;
        for l in left {
            res =res.max(l);
        }
        for r in right {
            res = res.max(n - r);
        }
        res
    }
}
