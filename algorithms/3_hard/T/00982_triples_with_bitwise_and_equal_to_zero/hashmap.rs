use std::collections::HashMap;

impl Solution {
    pub fn count_triplets(nums: Vec<i32>) -> i32 {
        let mut hashmap = HashMap::new();
        for &n1 in &nums {
            for &n2 in &nums {
                *hashmap.entry(n1 & n2).or_insert(0) += 1;
            }
        }

        let mut cnt = 0_i32;
        for num in nums {
            for (&other, &freq) in &hashmap {
                if num & other == 0 {
                    cnt += freq;
                }
            }
        }

        cnt
    }
}
