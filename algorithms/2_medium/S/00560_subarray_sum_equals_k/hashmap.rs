use std::collections::HashMap;

impl Solution {
    pub fn subarray_sum(nums: Vec<i32>, k: i32) -> i32 {
        let mut hashmap: HashMap<i32, i32> = HashMap::with_capacity(nums.len() + 1);
        hashmap.insert(0, 1);
        let mut sum = 0_i32;
        let mut cnt = 0_i32;

        for num in nums {
            sum += num;
            if let Some(freq) = hashmap.get(&(sum - k)) {
                cnt += *freq;
            }

            *hashmap.entry(sum).or_insert(0) += 1;
        }

        cnt
    }
}
