impl Solution {
    pub fn find_min_height_trees(n: i32, edges: Vec<Vec<i32>>) -> Vec<i32> {
        if n == 1 { return vec![0_i32]; }

        let mut deg = vec![0_i32; n as usize];
        let mut adj = vec![Vec::<i32>::new(); n as usize];
        for e in edges {
            let (u, v) = (e[0], e[1]);
            deg[u as usize] += 1;
            deg[v as usize] += 1;
            adj[u as usize].push(v);
            adj[v as usize].push(u);
        }

        let mut remain_nodes = n;
        let mut curr_leaves: Vec<i32> = (0..n).into_iter().filter(|&i| deg[i as usize] == 1).collect();
        let mut next_leaves: Vec<i32> = Vec::new();
        while remain_nodes > 2 {
            remain_nodes -= curr_leaves.len() as i32;
            next_leaves.clear();
            for &l in &curr_leaves {
                deg[l as usize] = 0;

                for &v in &adj[l as usize] {
                    if deg[v as usize] == 0 { continue; }

                    deg[v as usize] -= 1;
                    if deg[v as usize] == 1 {
                        next_leaves.push(v);
                    }
                }
            }
            (curr_leaves, next_leaves) = (next_leaves, curr_leaves);
        }

        curr_leaves.clone()
    }
}
