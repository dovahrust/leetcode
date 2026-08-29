use std::collections::HashMap;

impl Solution {
    pub fn flipgame(fronts: Vec<i32>, backs: Vec<i32>) -> i32 {
        assert!(fronts.len() == backs.len());
        let len = fronts.len();
        let mut hashmap: HashMap<i32, bool> = HashMap::new();

        for i in 0..len {
            let (f, b) = (fronts[i], backs[i]);

            if f != b {
                hashmap.entry(f).or_insert(true);
                hashmap.entry(b).or_insert(true);
            } else {
                *hashmap.entry(f).or_insert(false) = false;
            }
        }

        let mut res: Option<i32> = None;

        for (num, state) in hashmap {
            if state {
                res = match res {
                    None => Some(num),
                    Some(x) => Some(x.min(num)),
                };
            }
        }

        match res {
            None => 0,
            Some(x) => x,
        }
    }
}
