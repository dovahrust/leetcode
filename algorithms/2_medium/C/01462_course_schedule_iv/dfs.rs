impl Solution {
    fn dfs(u: i32, adj: &[Vec<i32>], seen: &mut[bool]) {
        if seen[u as usize] { return; }

        seen[u as usize] = true;
        for &v in &adj[u as usize] {
            Self::dfs(v, adj, seen);
        }
    }

    pub fn check_if_prerequisite(num_courses: i32, prerequisites: Vec<Vec<i32>>, queries: Vec<Vec<i32>>) -> Vec<bool> {
        let mut adj: Vec<Vec<i32>> = vec![Vec::default(); num_courses as usize];
        for p in prerequisites {
            let (u, v) = (p[0], p[1]);
            adj[u as usize].push(v);
        }

        let mut reachable = vec![false; (num_courses * num_courses) as usize];

        for head in 0..num_courses {
            let st = (head * num_courses) as usize;
            let end = st + num_courses as usize;
            Self::dfs(head, &adj, &mut reachable[st..end]);
        }

        let mut res = Vec::with_capacity(queries.len());
        for q in queries {
            res.push(reachable[(q[0] * num_courses + q[1]) as usize]);
        }

        res
    }
}
