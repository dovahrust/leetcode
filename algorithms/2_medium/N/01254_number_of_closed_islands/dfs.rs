impl Solution {
    const LAND: i32 = 0;
    const WATER: i32 = 1;
    const LAND_VISITED: i32 = -1;

    fn dfs(
        grid: &mut [Vec<i32>],
        cols: isize,
        i: isize,
        j: isize,
    ) {
        let rows = grid.len() as isize;
        if i < 0 || i >= rows || j < 0 || j >= cols || grid[i as usize][j as usize] != Self::LAND { return; }

        grid[i as usize][j as usize] = Self::LAND_VISITED;

        Self::dfs(grid, cols, i + 1, j);
        Self::dfs(grid, cols, i - 1, j);
        Self::dfs(grid, cols, i, j + 1);
        Self::dfs(grid, cols, i, j - 1);
    }

    pub fn closed_island(mut grid: Vec<Vec<i32>>) -> i32 {
        let rows = grid.len() as isize;
        let cols = grid[0].len() as isize;
        let mut cnt: i32 = 0;

        for i in 0..rows {
            Self::dfs(&mut grid, cols, i, 0);
            Self::dfs(&mut grid, cols, i, cols - 1);
        }

        for j in 0..cols {
            Self::dfs(&mut grid, cols, 0, j);
            Self::dfs(&mut grid, cols, rows - 1, j);
        }

        for i in 0..rows {
            for j in 0..cols {
                if grid[i as usize][j as usize] == Self::LAND {
                    cnt += 1;
                    Self::dfs(&mut grid, cols, i, j);
                }
            }
        }

        cnt
    }
}
