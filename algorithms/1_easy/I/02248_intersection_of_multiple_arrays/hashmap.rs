use std::collections::HashMap;

impl Solution {
    pub fn intersection(nums: Vec<Vec<i32>>) -> Vec<i32> {
        let mut hashmap: HashMap<i32, usize> = HashMap::new();
        let len = nums.len();

        for arr in nums {
            for v in arr {
                *hashmap.entry(v).or_insert(0) += 1;
            }
        }

        let mut res = hashmap.into_iter().filter(|x| x.1 == len).map(|x| x.0).collect::<Vec<_>>();
        res.sort_unstable();
        res
    }
}
