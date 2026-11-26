use std::collections::HashMap;

impl Solution {
    pub fn partition_array(nums: Vec<i32>, k: i32) -> bool {
        let k = k as usize;
        if nums.len() % k != 0 { return false; }

        let max_allow = nums.len() / k;
        let mut hashmap: HashMap<i32, usize> = HashMap::new();
        for num in nums {
            let entry = hashmap.entry(num).or_insert(0);
            *entry += 1;

            if *entry > max_allow { return false; }
        }

        true
    }
}
