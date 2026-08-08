use std::collections::VecDeque;

impl Solution {
    pub fn shortest_path_length(graph: Vec<Vec<i32>>) -> i32 {
        let n = graph.len();
        assert!(n >= 1 && n <= 12);
        let full = ((1 << n) - 1) as u16;
        let states_cols = (1 << n);
        let mut states = vec![false; states_cols * n];
        let mut q: VecDeque<(i32, u16, u16)> = VecDeque::with_capacity(n * 10);

        for u in 0..(n as u16) {
            let seen_node = 1_u16 << u;
            states[states_cols * (u as usize) + (seen_node as usize)] = false;
            q.push_back((0, seen_node, u));
        }

        while let Some((cost, seen, u)) = q.pop_front() {
            if seen == full {
                return cost;
            }
            for &v in &graph[u as usize] {
                let mask = 1_u16 << (v as u16);
                let new_seen = (mask | seen);
                if !states[states_cols * (v as usize) + (new_seen as usize)] {
                    states[states_cols * (v as usize) + (new_seen as usize)] = true;
                    q.push_back((cost + 1, new_seen, v as u16));
                }
            }
        }

        unreachable!("invalid input")
    }
}
