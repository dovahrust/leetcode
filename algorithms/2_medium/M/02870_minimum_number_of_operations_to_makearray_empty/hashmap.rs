use std::collections::HashMap;

impl Solution {
    pub fn min_operations(nums: Vec<i32>) -> i32 {
        let mut hashmap: HashMap<i32, i32> = HashMap::new();

        for num in nums {
            *hashmap.entry(num).or_insert(0) += 1;
        }

        let mut res: i32 = 0;
        for (_, freq) in hashmap {
            if freq == 1 {
                return -1;
            }

            // 6 => 3, 3,
            // 7 => 3, 2, 2
            // 8 => 3, 3, 2
            res += (freq + 2) / 3;
        }

        res
    }
}
