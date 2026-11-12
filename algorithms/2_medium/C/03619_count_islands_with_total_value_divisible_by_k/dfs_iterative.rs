impl Solution {
    const DIRECTIONS: [(isize, isize); 4] = [(1, 0), (-1, 0), (0, 1), (0, -1)];

    fn dfs_iterative(grid: &mut [Vec<i32>], stack: &mut Vec<(isize, isize)>, si: isize, sj: isize, rows: isize, cols: isize) -> i64 {
        let mut sum = grid[si as usize][sj as usize] as i64;
        grid[si as usize][sj as usize] = 0;
        stack.clear();
        stack.push((si, sj));

        while let Some((i, j)) = stack.pop() {
            for (dx, dy) in Self::DIRECTIONS {
                let ni = i + dx;
                let nj = j + dy;

                if ni < 0 || ni >=  rows || nj < 0 || nj >= cols || grid[ni as usize][nj as usize] == 0 { continue; }

                sum += grid[ni as usize][nj as usize] as i64;
                grid[ni as usize][nj as usize] = 0;
                stack.push((ni, nj));
            }
        }

        sum
    }

    pub fn count_islands(mut grid: Vec<Vec<i32>>, k: i32) -> i32 {
        let mut count = 0;
        let rows = grid.len() as isize;
        let cols = grid[0].len() as isize;
        let k = k as i64;
        let mut stack: Vec<(isize, isize)> = Vec::new();

        for i in 0..rows {
            for j in 0..cols {
                if grid[i as usize][j as usize] != 0 {
                    let sum = Self::dfs_iterative(&mut grid, &mut stack, i, j, rows, cols);

                    if sum % k == 0 { count += 1; }
                }
            }
        }

        count
    }
}
