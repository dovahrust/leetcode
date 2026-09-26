use std::collections::HashSet;

impl Solution {
    pub fn minimum_operations(nums: Vec<i32>) -> i32 {
        nums.into_iter().collect::<HashSet<_>>().into_iter().filter(|&x| x != 0).count().try_into().unwrap()
    }
}
