use std::collections::VecDeque;

impl Solution {
    pub fn max_probability(n: i32, edges: Vec<Vec<i32>>, succ_prob: Vec<f64>, start_node: i32, end_node: i32) -> f64 {
        let (n, st, ed) = (n as usize, start_node as usize, end_node as usize);

        let mut adj: Vec<Vec<(usize, f64)>> = vec![Vec::new(); n];
        for (i, e) in edges.into_iter().enumerate() {
            let (u, v, w) = (e[0] as usize, e[1] as usize, succ_prob[i]);
            if w > 0.0_f64 {
                adj[u].push((v, w));
                adj[v].push((u, w));
            }
        }

        let mut prob = vec![0.0_f64; n];
        let mut in_q = vec![false; n];
        let mut q: VecDeque<usize> = VecDeque::with_capacity(n);
        prob[st] = 1.0_f64;
        q.push_back(st);
        in_q[st] = true;

        while let Some(u) = q.pop_front() {
            in_q[u] = false;
            let prob_u = prob[u];
            for &(v, w) in &adj[u] {
                if w * prob_u > prob[v] {
                    prob[v] = w * prob_u;
                    if !in_q[v] {
                        in_q[v] = true;
                        q.push_back(v);
                    }
                }
            }
        }

        prob[ed]
    }
}
