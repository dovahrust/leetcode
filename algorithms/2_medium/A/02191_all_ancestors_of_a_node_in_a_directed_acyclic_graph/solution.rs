impl Solution {
    pub fn get_ancestors(n: i32, edges: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let n = n as usize;
        let mut rev_adj: Vec<Vec<i32>> = vec![Vec::new(); n];
        for e in edges {
            let (u, v) = (e[0], e[1]);
            rev_adj[v as usize].push(u);
        }

        let mut seen = vec![false; n];
        let mut stack: Vec<i32> = Vec::with_capacity(n);
        let mut res: Vec<Vec<i32>> = vec![Vec::new(); n];

        for v in 0..n {
            stack.clear();
            stack.push(v as i32);
            seen.fill(false);
            seen[v] = true;

            while let Some(node) = stack.pop() {
                for &parent in &rev_adj[node as usize] {
                    if !seen[parent as usize] {
                        res[v].push(parent);
                        seen[parent as usize] = true;
                        stack.push(parent);
                    }
                }
            }

            res[v].sort_unstable();
        }

        res
    }
}
