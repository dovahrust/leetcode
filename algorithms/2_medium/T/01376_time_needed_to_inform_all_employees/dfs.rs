impl Solution {
    pub fn num_of_minutes(n: i32, head_id: i32, manager: Vec<i32>, inform_time: Vec<i32>) -> i32 {
        let mut adj: Vec<Vec<i32>> = vec![Vec::new(); n as usize];
        for (v, m) in manager.into_iter().enumerate() {
            if m != -1 {
                adj[m as usize].push(v as i32);
            }
        }
        let mut stack: Vec<(i32, i32)> = Vec::with_capacity(n as usize);
        stack.push((0, head_id));
        let mut res = 0_i32;

        while let Some((cost, u)) = stack.pop() {
            res = res.max(cost);
            let new_cost = cost + inform_time[u as usize];
            for &v in &adj[u as usize] {
                stack.push((new_cost, v));
            }
        }

        res
    }
}
