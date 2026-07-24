use std::collections::HashMap;

impl Solution {
    pub fn longest_subsequence(arr: Vec<i32>, difference: i32) -> i32 {
        let mut hashmap: HashMap<i32, i32> = HashMap::new();
        let mut res = 0_i32;

        for a in arr {
            let mut curr = 1;
            if let Some(val) = hashmap.get(&(a - difference)) {
                curr = 1 + *val;
            }

            *hashmap.entry(a).or_insert(0) = curr;
            res = res.max(curr);
        }

        res
    }
}
