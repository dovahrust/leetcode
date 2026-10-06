use std::collections::HashMap;

impl Solution {
    pub fn max_equal_adjacent_pairs(nums: Vec<i32>) -> i32 {
        let mut hashmap: HashMap<(i32, i32), i32> = HashMap::new();
        let mut sum_eq: i32 = 0;

        for w in nums.windows(2) {
            if w[0] == w[1] {
                sum_eq += 1;
            } else {
                *hashmap.entry((w[0].min(w[1]), w[0].max(w[1]))).or_insert(0) += 1;
            }
        }

        sum_eq + hashmap.into_iter().map(|(_, freq)| freq).max().unwrap_or(0)
    }
}
