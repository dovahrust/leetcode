impl Solution {
    pub fn find_poisoned_duration(time_series: Vec<i32>, duration: i32) -> i32 {
        let mut curr = 0_i32;
        let mut res = 0_i32;
        for t in time_series {
            curr = curr.max(t);
            res += t + duration - curr;
            curr = t + duration;
        }

        res
    }
}
