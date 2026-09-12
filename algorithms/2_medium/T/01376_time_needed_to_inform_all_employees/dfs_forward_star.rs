impl Solution {
    pub fn num_of_minutes(n: i32, head_id: i32, manager: Vec<i32>, inform_time: Vec<i32>) -> i32 {
        let mut adj: Vec<(i32, i32)> = Vec::with_capacity(2 * (n as usize) - 1);
        for i in 0..n {
            adj.push((-1, -1));
        }
        for (v, m) in manager.into_iter().enumerate() {
            if m != -1 {
                let next = adj[m as usize].1;
                adj[m as usize].1 = adj.len() as i32;
                adj.push((v as i32, next));
            }
        }
        let mut stack: Vec<(i32, i32)> = Vec::with_capacity(n as usize);
        stack.push((0, head_id));
        let mut res = 0_i32;

        while let Some((cost, u)) = stack.pop() {
            res = res.max(cost);
            let new_cost = cost + inform_time[u as usize];
            let mut curr = adj[u as usize].1;
            while curr != -1 {
                stack.push((new_cost, adj[curr as usize].0));
                curr = adj[curr as usize].1;
            }
        }

        res
    }
}
