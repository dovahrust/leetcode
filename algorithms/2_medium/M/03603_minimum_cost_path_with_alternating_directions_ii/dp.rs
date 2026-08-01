impl Solution {
    pub fn min_cost(m: i32, n: i32, wait_costs: Vec<Vec<i32>>) -> i64 {
        assert!(!wait_costs.is_empty());
        let (rows, cols) = (wait_costs.len(), wait_costs[0].len());
        assert!(rows > 0 && cols > 0 && 100_000 / cols >= rows && rows * cols >= 2);
        let mut buff = vec![i64::MAX; 2 * cols];
        let (mut prev, mut curr) = buff.split_at_mut(cols);
        prev[0] = 0;
        for i in 0..rows {
            for j in 0..cols {
                let entry_cost = (i as i64 + 1) * (j as i64 + 1);
                let wait_cost = if (i == 0 && j == 0) || (i == rows - 1 && j == cols - 1) {
                    0
                } else {
                    wait_costs[i][j]
                };
                let up = prev[j];
                let left = if j == 0 { i64::MAX } else { curr[j - 1] };
                curr[j] = up.min(left) + entry_cost + wait_cost as i64;
            }
            (prev, curr) = (curr, prev);
        }

        prev[cols - 1]
    }
}
