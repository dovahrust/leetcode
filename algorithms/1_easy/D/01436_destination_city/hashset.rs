use std::collections::HashSet;

impl Solution {
    pub fn dest_city(paths: Vec<Vec<String>>) -> String {
        let mut hashset: HashSet<&str> = HashSet::with_capacity(paths.len() * 3);

        for p in &paths {
            hashset.insert(p[0].as_str());
        }

        for p in &paths {
            if !hashset.contains(&p[1].as_str()) {
                return p[1].clone();
            }
        }

        unreachable!("invalid input")
    }
}
