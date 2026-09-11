impl Solution {
    pub fn find_order(num_courses: i32, prerequisites: Vec<Vec<i32>>) -> Vec<i32> {
        let mut adj: Vec<Vec<i32>> = vec![Vec::new(); num_courses as usize];
        let mut indeg = vec![0_u32; num_courses as usize];
        let mut stack: Vec<i32> = Vec::new();
        let mut res: Vec<i32> = Vec::with_capacity(num_courses as usize);

        for p in prerequisites {
            let (v, u) = (p[0], p[1]);
            indeg[v as usize] += 1;
            adj[u as usize].push(v);
        }

        for (node, d) in indeg.iter().enumerate() {
            if *d == 0 {
                stack.push(node as i32);
            }
        }

        while let Some(u) = stack.pop() {
            res.push(u);
            for &v in &adj[u as usize] {
                indeg[v as usize] -= 1;
                if indeg[v as usize] == 0 {
                    stack.push(v);
                }
            }
        }

        if res.len() != num_courses as usize {
            return Vec::new();
        }

        res
    }
}
