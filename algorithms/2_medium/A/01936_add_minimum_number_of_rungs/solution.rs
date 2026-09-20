impl Solution {
    pub fn add_rungs(rungs: Vec<i32>, dist: i32) -> i32 {
        let mut curr: i32 = 0;
        let mut cnt: i32 = 0;
        for next in rungs {
            let width = next - curr;
            cnt += (width - 1) / dist;
            curr = next;
        }
        cnt
    }
}
