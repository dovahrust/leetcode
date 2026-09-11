impl Solution {
    pub fn eventual_safe_nodes(graph: Vec<Vec<i32>>) -> Vec<i32> {
        let n = graph.len();
        let mut outdeg: Vec<u32> = vec![0_u32; n];
        let mut rev_adj: Vec<Vec<i32>> = vec![Vec::new(); n];
        for (u, g) in graph.iter().enumerate() {
            outdeg[u] = g.len() as u32;

            for &v in g {
                rev_adj[v as usize].push(u as i32);
            }
        }

        let mut stack: Vec<i32> = Vec::with_capacity(n);
        for (u, &od) in outdeg.iter().enumerate() {
            if od == 0 {
                stack.push(u as i32);
            }
        }

        while let Some(v) = stack.pop() {
            for &u in &rev_adj[v as usize] {
                outdeg[u as usize] -= 1;
                if outdeg[u as usize] == 0 {
                    stack.push(u as i32);
                }
            }
        }

        outdeg.into_iter().enumerate().filter(|&(i, d)| d == 0).map(|(i, _)| i as i32).collect()
    }
}
