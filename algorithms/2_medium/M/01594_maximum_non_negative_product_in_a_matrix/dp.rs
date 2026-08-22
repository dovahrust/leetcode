impl Solution {
    const MOD: i64 = 1_000_000_007;

    pub fn max_product_path(grid: Vec<Vec<i32>>) -> i32 {
        assert!(!grid.is_empty() && !grid[0].is_empty());
        let (rows, cols) = (grid.len(), grid[0].len());
        let mut buff = vec![(0_i64, 0_i64); 2 * cols];
        let (mut prev, mut curr) = buff.split_at_mut(cols);

        prev[0] = (grid[0][0] as i64, grid[0][0] as i64);
        for j in 1..cols {
            let v = (prev[j - 1].0 * grid[0][j] as i64);
            prev[j] = (v, v);
        }

        for i in 1..rows {
            let v = (prev[0].0 * grid[i][0] as i64);
            curr[0] = (v, v);

            for j in 1..cols {
                let cell = grid[i][j] as i64;
                let a = (prev[j].0 * cell);
                let b = (prev[j].1 * cell);
                let c = (curr[j - 1].0 * cell);
                let d = (curr[j - 1].1 * cell);

                curr[j] = (a.min(b).min(c).min(d), a.max(b).max(c).max(d));
            }
            (curr, prev) = (prev, curr);
        }

        if prev[cols - 1].1 < 0 {
            return -1;
        }

        (prev[cols - 1].1 % Self::MOD) as i32
    }
}
