impl Solution {
    fn dfs(grid: &mut [Vec<i32>], cols: isize, i: isize, j: isize) -> i32 {
        let rows = grid.len() as isize;
        if (i < 0 || j < 0 || i >= rows || j >= cols || grid[i as usize][j as usize] == 0) {
            return 0;
        }

        let val = grid[i as usize][j as usize];

        grid[i as usize][j as usize] = 0;
        let res = (val + Self::dfs(grid, cols, i - 1, j))
                  .max(val + Self::dfs(grid, cols, i + 1, j))
                  .max(val + Self::dfs(grid, cols, i, j - 1))
                  .max(val + Self::dfs(grid, cols, i, j + 1));
        grid[i as usize][j as usize] = val;

        res
    }

    pub fn get_maximum_gold(mut grid: Vec<Vec<i32>>) -> i32 {
        assert!(grid.len() > 0 && grid[0].len() > 0);
        let (rows, cols) = (grid.len() as isize, grid[0].len() as isize);
        assert!(rows <= 15 && cols <= 15);

        let mut res = 0_i32;

        for i in 0..rows {
            for j in 0..cols {
                res = res.max(Self::dfs(&mut grid, cols, i, j));
            }
        }

        res
    }
}
