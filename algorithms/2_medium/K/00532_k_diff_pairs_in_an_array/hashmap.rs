use std::collections::HashMap;

impl Solution {
    pub fn find_pairs(nums: Vec<i32>, k: i32) -> i32 {
        let mut hashmap: HashMap<i32, i32> = HashMap::with_capacity(nums.len() * 12 / 10);
        for num in nums {
            *hashmap.entry(num).or_insert(0) += 1;
        }

        let mut cnt = 0_i32;
        for (&num, &freq) in &hashmap {
            if k == 0 {
                if freq >= 2 {
                    cnt += 1;
                }
            } else if hashmap.contains_key(&(num + k)) {
                cnt += 1;
            }
        }

        cnt
    }
}
