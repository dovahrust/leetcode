impl Solution {
    pub fn find_missing_elements(mut nums: Vec<i32>) -> Vec<i32> {
        nums.sort_unstable();
        let mut res: Vec<i32> = Vec::new();

        for window in nums.windows(2) {
            for missed_num in (window[0]..window[1]).skip(1) {
                res.push(missed_num);
            }
        }

        res
    }
}
