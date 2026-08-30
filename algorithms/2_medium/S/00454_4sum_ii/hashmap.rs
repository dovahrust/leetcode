use std::collections::HashMap;

impl Solution {
    pub fn four_sum_count(nums1: Vec<i32>, nums2: Vec<i32>, nums3: Vec<i32>, nums4: Vec<i32>) -> i32 {
        let mut hashmap: HashMap<i32, i32> = HashMap::with_capacity(nums1.len() * 4);
        let mut cnt = 0_i32;

        for &n1 in &nums1 {
            for &n2 in &nums2 {
                *hashmap.entry(n1 + n2).or_insert(0) += 1;
            }
        }

        for &n3 in &nums3 {
            for &n4 in &nums4 {
                let sum = n3 + n4;
                let other = -sum;

                if let Some(&freq) = hashmap.get(&other) {
                    cnt += freq
                }
            }
        }

        cnt
    }
}
