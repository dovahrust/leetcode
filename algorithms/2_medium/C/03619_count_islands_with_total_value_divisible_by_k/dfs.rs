impl Solution {
    fn dfs(grid: &mut [Vec<i32>], i: isize, j: isize, cols: isize) -> i64 {
        let rows = grid.len() as isize;

        if i < 0 || i >= rows || j < 0 || j >= cols || grid[i as usize][j as usize] == 0 { return 0; }

        let curr = grid[i as usize][j as usize] as i64;
        grid[i as usize][j as usize] = 0;

        curr +
        Self::dfs(grid, i - 1, j, cols) +
        Self::dfs(grid, i + 1, j, cols) +
        Self::dfs(grid, i, j - 1, cols) +
        Self::dfs(grid, i, j + 1, cols)
    }

    pub fn count_islands(mut grid: Vec<Vec<i32>>, k: i32) -> i32 {
        let mut count = 0;
        let rows = grid.len() as isize;
        let cols = grid[0].len() as isize;
        let k = k as i64;

        for i in 0..rows {
            for j in 0..cols {
                if grid[i as usize][j as usize] != 0 {
                    let sum = Self::dfs(&mut grid, i, j, cols);

                    if sum % k == 0 { count += 1; }
                }
            }
        }

        count
    }
}
