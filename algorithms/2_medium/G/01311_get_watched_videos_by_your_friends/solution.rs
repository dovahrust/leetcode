use std::collections::{HashMap, VecDeque};

impl Solution {
    pub fn watched_videos_by_friends(watched_videos: Vec<Vec<String>>, friends: Vec<Vec<i32>>, id: i32, level: i32) -> Vec<String> {
        assert!(
            friends.len() == watched_videos.len() &&
            id >= 0 && (id as usize) < friends.len() &&
            level >= 1 && (level as usize) < friends.len()
        );

        let n = friends.len();
        let mut adj: Vec<Vec<i32>> = vec![Vec::new(); n];
        for (u, f) in friends.into_iter().enumerate() {
            for v in f {
                adj[u].push(v);
                adj[v as usize].push(u as i32);
            }
        }

        let mut q: VecDeque<i32> = VecDeque::with_capacity(n);
        let mut seen = vec![false; n];
        seen[id as usize] = true;
        q.push_back(id);
        let mut curr_level = 0_i32;
        while !q.is_empty() {
            let q_len = q.len();
            for _ in 0..q_len {
                let u = q.pop_front().unwrap();
                for &v in &adj[u as usize] {
                    if !seen[v as usize] {
                        seen[v as usize] = true;
                        q.push_back(v);
                    }
                }
            }

            curr_level += 1;
            if curr_level == level {
                break;
            } 
        }

        let mut res_map: HashMap<&String, u32> = HashMap::new();
        while let Some(node) = q.pop_front() {
            for s in &watched_videos[node as usize] {
                *res_map.entry(s).or_insert(0) += 1;
            }
        }

        let mut res_vec: Vec<(String, u32)> = res_map.into_iter().map(|(x, freq)| (x.to_string(), freq)).collect();
        res_vec.sort_unstable_by(|a, b| {
            if a.1 == b.1 {
                a.0.cmp(&b.0)
            } else {
                a.1.cmp(&b.1)
            }
        });

        res_vec.into_iter().map(|x| x.0).collect()
    }
}
