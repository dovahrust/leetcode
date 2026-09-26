impl Solution {
    pub fn max_probability(n: i32, edges: Vec<Vec<i32>>, succ_prob: Vec<f64>, start_node: i32, end_node: i32) -> f64 {
        let (n, st, ed) = (n as usize, start_node as usize, end_node as usize);
        let mut prob = vec![0.0_f64; n];
        prob[st] = 1.0_f64;

        for _ in 0..n {
            let mut has_update = false;

            for (i, e) in edges.iter().enumerate() {
                let (u, v, w) = (e[0] as usize, e[1] as usize, succ_prob[i]);
                if w * prob[u] > prob[v] {
                    prob[v] = w * prob[u];
                    has_update = true;
                }

                if w * prob[v] > prob[u] {
                    prob[u] = w * prob[v];
                    has_update = true;
                }
            }

            if !has_update { break; }
        }

        prob[ed]
    }
}
