use std::collections::{HashMap, HashSet};

impl Solution {
    pub fn display_table(orders: Vec<Vec<String>>) -> Vec<Vec<String>> {
        let mut hashmap: HashMap<&str, HashMap<&str, i32>> = HashMap::new();
        let mut tables: HashSet<&str> = HashSet::new();

        for o in &orders {
            let (name, table, food) = (&o[0], &o[1], &o[2]);
            *hashmap.entry(food).or_insert(HashMap::new()).entry(table).or_insert(0) += 1;
            tables.insert(table);
        }

        let cols = hashmap.len() + 1;
        let rows = tables.len() + 1;
        let mut res: Vec<Vec<String>> = vec![vec![String::new(); cols]; rows];
        res[0][0] = "Table".to_string();
        for (j, key) in hashmap.keys().enumerate() {
            res[0][j + 1] = key.to_string();
        }
        res[0][1..].sort_unstable();
        for (i, t) in tables.into_iter().enumerate() {
            res[i + 1][0] = t.to_string();
        }
        res[1..].sort_unstable_by(|a, b| {
            if a[0].len() != b[0].len() {
                a[0].len().cmp(&b[0].len())
            } else {
                a[0].cmp(&b[0])
            }
        });

        for i in 1..rows {
            for j in 1..cols {
                if let Some(cnt) = hashmap[res[0][j].as_str()].get(res[i][0].as_str()) {
                    res[i][j] = cnt.to_string();
                } else {
                    res[i][j] = "0".to_string();
                }
            }
        }

        res
    }
}
