impl Solution {
    pub fn can_finish(num_courses: i32, prerequisites: Vec<Vec<i32>>) -> bool {
        let mut rev_adj: Vec<Vec<i32>> = vec![Vec::default(); num_courses as usize];
        let mut deg = vec![0_i32; num_courses as usize];
        for p in prerequisites {
            let (u, v) = (p[0], p[1]);
            rev_adj[v as usize].push(u);
            deg[u as usize] += 1;
        }

        let mut stack: Vec<i32> = Vec::with_capacity(num_courses as usize);

        for (node, &d) in deg.iter().enumerate() {
            if d == 0 {
                stack.push(node as i32);
            }
        }

        let mut cnt: i32 = 0;
        while let Some(v) = stack.pop() {
            cnt += 1;
            for &u in &rev_adj[v as usize] {
                deg[u as usize] -= 1;
                if deg[u as usize] == 0 {
                    stack.push(u);
                }
            }
        }

        cnt == num_courses
    }
}
