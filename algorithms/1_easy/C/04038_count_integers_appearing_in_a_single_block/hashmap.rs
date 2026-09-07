use std::collections::HashMap;

impl Solution {
    pub fn count_special_integers(nums: Vec<i32>) -> i32 {
        if nums.is_empty() { return 0; }

        let mut hashmap: HashMap<i32, bool> = HashMap::with_capacity(nums.len() * 2);
        hashmap.insert(nums[0], true);
        let len = nums.len();

        for i in 1..len {
            if nums[i] != nums[i - 1] {
                hashmap.entry(nums[i]).and_modify(|x| *x = false).or_insert(true);
            }
        }

        hashmap.into_iter().filter(|&(_, state)| state).count().try_into().unwrap()
    }
}
