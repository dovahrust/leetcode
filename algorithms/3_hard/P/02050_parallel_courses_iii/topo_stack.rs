impl Solution {
    pub fn minimum_time(n: i32, relations: Vec<Vec<i32>>, time: Vec<i32>) -> i32 {
        let mut adj: Vec<Vec<i32>> = vec![Vec::new(); n as usize];
        let mut deg: Vec<u32> = vec![0_u32; n as usize];
        let mut min_st_time = vec![0_i32; n as usize];
        for r in relations {
            let (u, v) = (r[0] - 1, r[1] - 1);
            deg[v as usize] += 1;
            adj[u as usize].push(v);
        }

        let mut stack: Vec<i32> = Vec::with_capacity(n as usize);

        for (u, &d) in deg.iter().enumerate() {
            if d == 0 {
                stack.push(u as i32);
            }
        }

        let mut res: i32 = 0;
        while let Some(u) = stack.pop() {
            let prev_end = min_st_time[u as usize] + time[u as usize];
            res = res.max(prev_end);

            for &v in &adj[u as usize] {
                deg[v as usize] -= 1;
                min_st_time[v as usize] = min_st_time[v as usize].max(prev_end);
                if deg[v as usize] == 0 {
                    stack.push(v);
                }
            }
        }

        res
    }
}
