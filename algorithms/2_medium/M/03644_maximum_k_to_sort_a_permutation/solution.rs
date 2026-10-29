impl Solution {
    pub fn sort_permutation(nums: Vec<i32>) -> i32 {
        let mut res: Option<i32> = None;

        for (i, num) in nums.into_iter().enumerate() {
            if num != (i as i32) {
                res = match res {
                    Some(v) => Some(v & num),
                    None => Some(num),
                };
            }
        }

        res.unwrap_or(0)
    }
}
