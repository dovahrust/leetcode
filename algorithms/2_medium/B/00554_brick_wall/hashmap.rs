use std::collections::HashMap;

impl Solution {
    pub fn least_bricks(wall: Vec<Vec<i32>>) -> i32 {
        assert!(wall.len() <= 10_000);
        let mut hashmap: HashMap<i64, i32> = HashMap::new();
        let total = wall.len() as i32;
        for w in wall {
            let cols = w.len();
            assert!(cols >= 1);
            let mut pos = 0_i64;
            for j in 0..(cols - 1) {
                pos += w[j] as i64;
                *hashmap.entry(pos).or_insert(0) += 1;
            }
        }

        let mut max_freq = 0;
        for (_, freq) in hashmap {
            max_freq = max_freq.max(freq);
        }

        total - max_freq
    }
}
