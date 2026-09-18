use std::collections::HashMap;

impl Solution {
    pub fn find_original_array(mut changed: Vec<i32>) -> Vec<i32> {
        if changed.is_empty() || (changed.len() & 1) == 1 { return vec![]; }

        let target_len = changed.len() / 2;
        changed.sort_unstable();
        let mut res: Vec<i32> = Vec::with_capacity(target_len);
        let mut hashmap: HashMap<i32, isize> = HashMap::new();

        for c in changed {
            let entry = hashmap.entry(c).or_insert(0);

            if *entry == 0 {
                if target_len == res.len() { return vec![]; }

                res.push(c);
                *hashmap.entry(2 * c).or_insert(0) += 1;
            } else {
                *entry -= 1;
            }
        }

        res
    }
}
