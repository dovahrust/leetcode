impl Solution {
    fn init_topo(k: i32, conditions: Vec<Vec<i32>>) -> Option<Vec<i32>> {
        let mut deg = vec![0_i32; k as usize];
        let mut adj = vec![Vec::<i32>::new(); k as usize];
        for c in conditions {
            let (u, v) = (c[0] - 1, c[1] - 1);
            deg[v as usize] += 1;
            adj[u as usize].push(v);
        }

        let mut stack: Vec<i32> = Vec::with_capacity(k as usize);

        for (i, &d) in deg.iter().enumerate() {
            if d == 0 {
                stack.push(i as i32);
            }
        }

        let mut res: Vec<i32> = Vec::with_capacity(k as usize);
        while let Some(u) = stack.pop() {
            res.push(u);
            for &v in &adj[u as usize] {
                deg[v as usize] -= 1;
                if deg[v as usize] == 0 {
                    stack.push(v);
                }
            }
        }

        match res.len() == k as usize {
            true => Some(res),
            false => None,
        }
    }

    pub fn build_matrix(k: i32, row_conditions: Vec<Vec<i32>>, col_conditions: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let Some(rows_topo) = Self::init_topo(k, row_conditions) else { return Vec::new(); };
        let Some(cols_topo) = Self::init_topo(k, col_conditions) else { return Vec::new(); };

        let mut res = vec![vec![0_i32; k as usize]; k as usize];
        let mut idx: Vec<(usize, usize)> = vec![(0, 0); k as usize];

        for (i, v) in rows_topo.into_iter().enumerate() {
            idx[v as usize].0 = i;
        }

        for (j, v) in cols_topo.into_iter().enumerate() {
            idx[v as usize].1 = j;
        }

        for (value, (i, j)) in idx.into_iter().enumerate() {
            res[i][j] = (value + 1) as i32;
        }

        res
    }
}
