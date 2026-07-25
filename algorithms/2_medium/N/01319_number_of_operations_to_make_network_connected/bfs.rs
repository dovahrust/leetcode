use std::collections::VecDeque;

impl Solution {
    pub fn make_connected(n: i32, connections: Vec<Vec<i32>>) -> i32 {
        assert!(n >= 1);
        let edges = connections.len() as i32;
        if edges < n - 1 {
            return -1;
        }

        let mut adj: Vec<Vec<i32>> = vec![Vec::default(); n as usize];
        for c in connections {
            assert!(c.len() == 2);
            let (u, v) = (c[0], c[1]);
            assert!(u >= 0 && v >= 0 && u < n && v < n);
            adj[u as usize].push(v);
            adj[v as usize].push(u);
        }
        let mut q: VecDeque<i32> = VecDeque::new();
        let mut seen = vec![false; n as usize];
        let mut groups = 0;

        for u in 0..n {
            if !seen[u as usize] {
                groups += 1;
                seen[u as usize] = true;
                q.push_back(u);

                while let Some(u) = q.pop_front() {
                    for &v in &adj[u as usize] {
                        if !seen[v as usize] {
                            seen[v as usize] = true;
                            q.push_back(v);
                        }
                    }
                }
            }
        }

        groups - 1
    }
}
