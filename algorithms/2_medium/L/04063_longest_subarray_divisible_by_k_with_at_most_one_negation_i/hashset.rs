use std::collections::HashSet;

impl Solution {
    pub fn longest_subarray(nums: Vec<i32>, k: i32) -> i32 {
        let len = nums.len();
        let mut hashset: HashSet<i32> = HashSet::new();
        let mut max: usize = 0;

        for i in 0..len {
            hashset.clear();
            let mut sum_mod: i32 = 0;
            for j in i..len {
                let mod_by_k = ((nums[j] % k) + k) % k;
                sum_mod = (sum_mod + mod_by_k) % k;

                if mod_by_k != 0 {
                    let mod_by_k_comp = k - mod_by_k;
                    hashset.insert((mod_by_k - mod_by_k_comp + k) % k);
                }
                
                if sum_mod == 0 || hashset.contains(&(sum_mod)) {
                    max = max.max(j - i + 1);
                }
            }
        }

        max.try_into().unwrap()
    }
}
