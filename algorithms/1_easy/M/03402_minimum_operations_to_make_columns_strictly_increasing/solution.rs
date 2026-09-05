impl Solution {
    pub fn minimum_operations(grid: Vec<Vec<i32>>) -> i32 {
        if grid.len() <= 1 { return 0; }

        let (rows, cols) = (grid.len(), grid[0].len());
        let mut sum = 0;

        for j in 0..cols {
            let mut prev = grid[0][j];
            for i in 1..rows {
                let target = prev + 1;
                sum += std::cmp::max(0, target - grid[i][j]);
                prev = target.max(grid[i][j]);
            }
        }

        sum
    }
}
