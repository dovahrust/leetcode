use std::collections::HashMap;

impl Solution {
    pub fn top_k_frequent(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let len = nums.len();
        let k = k as usize;
        let mut hashmap: HashMap<i32, usize> = HashMap::new();

        for num in nums.into_iter() {
            *hashmap.entry(num).or_insert(0) += 1;
        }

        let mut buckets: Vec<Vec<i32>> = vec![Vec::new(); len + 1];

        for (num, freq) in hashmap {
            buckets[freq].push(num);
        }

        let mut res: Vec<i32> = Vec::with_capacity(k);

        for b in buckets.into_iter().rev() {
            for num in b {
                res.push(num);
                if res.len() == k {
                    return res;
                }
            }
        }

        unreachable!("invalid input")
    }
}
