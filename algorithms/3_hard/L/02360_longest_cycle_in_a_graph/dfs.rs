impl Solution {
    pub fn longest_cycle(edges: Vec<i32>) -> i32 {
        let n = edges.len();
        let mut deg = vec![0_i32; n];
        for &v in &edges {
            if v != -1 {
                deg[v as usize] += 1;
            }
        }

        let mut stack: Vec<i32> = Vec::with_capacity(n);
        let mut seen = vec![false; n];

        for (node, &d) in deg.iter().enumerate() {
            if d == 0 {
                stack.push(node as i32);
            }
        }

        while let Some(u) = stack.pop() {
            seen[u as usize] = true;
            let v = edges[u as usize];
            if v != -1 {
                deg[v as usize] -= 1;
                if deg[v as usize] == 0 {
                    stack.push(v);
                }
            }
        }

        let mut res = -1_i32;

        for i in 0..n {
            if !seen[i] {
                let mut curr = 0_i32;
                stack.push(i as i32);
                while let Some(u) = stack.pop() {
                    seen[u as usize] = true;
                    curr += 1;
                    let v = edges[u as usize];
                    if v != -1 && !seen[v as usize] {
                        seen[v as usize] = true;
                        stack.push(v);
                    }
                }
                res = res.max(curr);
            }
        }

        res
    }
}
