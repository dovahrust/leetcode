use std::collections::HashMap;

impl Solution {
    pub fn max_selected_elements(mut nums: Vec<i32>) -> i32 {
        nums.sort_unstable();
        let mut hashmap: HashMap<i32, i32> = HashMap::with_capacity(2 * nums.len());

        for num in nums {
            let by_inc = *hashmap.get(&num).unwrap_or(&0) + 1;
            hashmap.insert(num + 1, by_inc);

            let by_keep = *hashmap.get(&(num - 1)).unwrap_or(&0) + 1;
            hashmap.insert(num, by_keep);
        }

        hashmap.into_iter().map(|x| x.1).max().unwrap()
    }
}
