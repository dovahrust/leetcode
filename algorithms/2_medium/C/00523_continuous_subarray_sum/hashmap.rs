use std::collections::HashMap;

impl Solution {
    pub fn check_subarray_sum(nums: Vec<i32>, k: i32) -> bool {
        assert!(k >= 1 && nums.len() <= 100_000);
        let mut hashmap: HashMap<i32, i32> = HashMap::with_capacity(nums.len() * 12 / 10);
        let mut prefix = 0_i32;

        hashmap.insert(0, -1);

        for (i, num) in nums.into_iter().enumerate() {
            prefix += num;
            let pref_mod_k = prefix % k;

            if let Some(first_seen) = hashmap.get(&pref_mod_k) {
                if (i as i32) - first_seen >= 2 {
                    return true;
                }
            } else {
                hashmap.insert(pref_mod_k, i as i32);
            }
        }

        false
    }
}
