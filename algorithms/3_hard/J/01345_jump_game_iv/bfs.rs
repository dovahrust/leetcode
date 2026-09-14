use std::collections::{HashMap, VecDeque};

impl Solution {
    pub fn min_jumps(arr: Vec<i32>) -> i32 {
        let len = arr.len();
        if len <= 1 { return 0; }
        if len == 2 || arr[0] == arr[len - 1] { return 1; }

        let mut hashmap: HashMap<i32, Vec<usize>> = HashMap::new();
        for (i, &a) in arr.iter().enumerate() {
            hashmap.entry(a).or_insert(Vec::new()).push(i);
        }

        let mut q: VecDeque<usize> = VecDeque::new();
        let mut seen = vec![false; len];
        for &idx in &hashmap[&arr[len - 1]] {
            q.push_back(idx);
            seen[idx] = true;
        }
        hashmap.get_mut(&arr[len - 1]).unwrap().clear();
        if !seen[len - 2] {
            seen[len - 2] = true;
            q.push_back(len - 2);
        }
        let mut level = 1;

        loop {
            if seen[0] { return level; }

            let q_len = q.len();

            for _ in 0..q_len {
                let idx = q.pop_front().unwrap();
                for &idx_with_same_val in &hashmap[&arr[idx]] {
                    if !seen[idx_with_same_val] {
                        q.push_back(idx_with_same_val);
                        seen[idx_with_same_val] = true;
                    }
                }
                hashmap.get_mut(&arr[idx]).unwrap().clear();
                if idx > 0 && !seen[idx - 1] {
                    q.push_back(idx - 1);
                    seen[idx - 1] = true;
                }

                if idx + 1 < len && !seen[idx + 1] {
                    q.push_back(idx + 1);
                    seen[idx + 1] = true;
                }
            }

            level += 1;
        }
    }
}
