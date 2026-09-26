impl Solution {
    const INF: usize = usize::MAX;

    fn dfs(parent: usize, u: usize, adj: &[Vec<usize>], has_apple: &[bool]) -> i32 {
        let mut child_costs: i32 = 0;
        for &v in &adj[u] {
            if v != parent {
                let cost = Self::dfs(u, v, adj, has_apple);
                child_costs += if cost > 0 || has_apple[v] { cost + 2 } else { 0 };
            }
        }

        child_costs
    }

    pub fn min_time(n: i32, edges: Vec<Vec<i32>>, has_apple: Vec<bool>) -> i32 {
        if has_apple.iter().all(|&x| x == false) { return 0; }

        let n = n as usize;
        let mut adj: Vec<Vec<usize>> = vec![Vec::new(); n];
        for e in edges {
            let (u, v) = (e[0] as usize, e[1] as usize);
            adj[u].push(v);
            adj[v].push(u);
        }

        Self::dfs(Self::INF, 0, &adj, &has_apple)
    }
}
