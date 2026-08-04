use std::collections::HashSet;

impl Solution {
    pub fn find_missing_elements(nums: Vec<i32>) -> Vec<i32> {
        assert!(num.len() > 0);
        let set: HashSet<i32> = nums.iter().map(|x| *x).collect();
        let max: i32 = *nums.iter().max().unwrap();
        let min: i32 = *nums.iter().min().unwrap();
        let width = (max as i64) - (min as i64) + 1;
        let res_len = (width as usize) - set.len();
        let mut res: Vec<i32> = Vec::with_capacity(res_len);

        for val in min..max {
            if !set.contains(&val) {
                res.push(val);
            }
        }

        res
    }
}
