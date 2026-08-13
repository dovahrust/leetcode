impl Solution {
    fn dfs(curr: i32, adj: &[(i32, i32)], visited: &mut [bool], cnt: &mut i32) -> i32 {
        visited[curr as usize] = true;

        let mut next_child = adj[curr as usize].1;
        let mut size = 1;
        let mut prev_child_size = -1_i32;
        let mut is_valid = true;

        while next_child != -1 {
            let v = adj[next_child as usize].0;
            next_child = adj[next_child as usize].1;

            if visited[v as usize] {
                continue;
            }

            let curr_child_size = Self::dfs(v, adj, visited, cnt);
            if prev_child_size == -1 {
                prev_child_size = curr_child_size;
            } else if prev_child_size != curr_child_size {
                is_valid = false;
            }

            size += curr_child_size;
        }

        if is_valid {
            *cnt += 1;
        }

        size
    }

    pub fn count_good_nodes(edges: Vec<Vec<i32>>) -> i32 {
        let n = edges.len() + 1;
        assert!(n <= 100_000 && n >= 2);
        let mut adj: Vec<(i32, i32)> = Vec::with_capacity(3 * n);
        for i in 0..n {
            adj.push((-1, -1));
        }
        for e in edges {
            assert!(e.len() == 2);
            let (u, v) = (e[0], e[1]);
            assert!(u >= 0 && v >= 0 && (u as usize) < n && (v as usize) < n);

            let next_v = adj[v as usize].1;
            adj[v as usize].1 = adj.len() as i32;
            adj.push((u, next_v));

            let next_u = adj[u as usize].1;
            adj[u as usize].1 = adj.len() as i32;
            adj.push((v, next_u));
        }

        let mut cnt = 0_i32;
        let mut visited = vec![false; n];

        Self::dfs(0, &adj, &mut visited, &mut cnt);

        cnt
    }
}
