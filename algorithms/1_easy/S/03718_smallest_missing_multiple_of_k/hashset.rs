use std::collections::HashSet;

impl Solution {
    pub fn missing_multiple(nums: Vec<i32>, k: i32) -> i32 {
        let hashset: HashSet<i32> = nums.iter().filter(|&&x| x % k == 0).map(|&x| x).collect();
        let mut curr = k;

        while hashset.contains(&curr) {
            curr += k;
        }

        curr
    }
}
