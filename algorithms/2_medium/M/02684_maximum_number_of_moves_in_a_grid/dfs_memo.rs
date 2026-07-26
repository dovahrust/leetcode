impl Solution {
    fn dfs(grid: &[Vec<i32>], cols: usize, i: usize, j: usize, memo: &mut [i32]) -> i32 {
        if j + 1 == cols {
            return 0;
        }

        let rows = grid.len();
        let memo_idx = i * cols + j;
        if memo[memo_idx] != -1 {
            return memo[memo_idx];
        }

        let mut max = 0_i32;
        let curr_val = grid[i][j];

        if i > 0 && grid[i - 1][j + 1] > curr_val {
            max = max.max(1 + Self::dfs(grid, cols, i - 1, j + 1, memo));
        }

        if grid[i][j + 1] > curr_val {
            max = max.max(1 + Self::dfs(grid, cols, i, j + 1, memo));
        }

        if i + 1 < rows && grid[i + 1][j + 1] > curr_val {
            max = max.max(1 + Self::dfs(grid, cols, i + 1, j + 1, memo));
        }

        memo[memo_idx] = max;
        max
    }

    pub fn max_moves(grid: Vec<Vec<i32>>) -> i32 {
        let rows = grid.len();
        let cols = grid[0].len();
        let mut memo = vec![-1_i32; rows * cols];
        let mut max = 0_i32;

        for i in 0..rows {
            max = max.max(Self::dfs(&grid, cols, i, 0, &mut memo));
        }

        max
    }
}
