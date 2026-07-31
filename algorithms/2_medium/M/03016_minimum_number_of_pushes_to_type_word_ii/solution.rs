use std::collections::HashMap;

impl Solution {
    pub fn minimum_pushes(word: String) -> i32 {
        assert!(word.len() <= 100_000);

        let mut freqs = [0_i32; 26];
        word.into_bytes().into_iter().for_each(|byte| {
            assert!(byte >= b'a' && byte <= b'z');
            freqs[(byte - b'a') as usize] += 1;
        });
        freqs.sort_unstable_by(|a, b| b.cmp(&a));

        let mut total_cost = 0_i32;

        for (index, val) in freqs.into_iter().enumerate() {
            let curr_cost = 1 + index  as i32 / 8;
            total_cost += val * curr_cost;
        }

        total_cost
    }
}
