impl Solution {
    fn dfs_is_sub(g1: &[Vec<i32>], g2: &[Vec<i32>], cols: isize, i: isize, j: isize, seen: &mut[bool]) -> bool {
        let rows = g1.len() as isize;
        if i < 0 || j < 0 || i >= rows || j >= cols {
            return true;
        }
        if seen[(i * cols + j) as usize] || g2[i as usize][j as usize] == 0 {
            return true;
        }

        let mut res = true;
        seen[(i * cols + j) as usize] = true;

        if g1[i as usize][j as usize] == 0 {
            res = false;
        }

        res &= Self::dfs_is_sub(g1, g2, cols, i + 1, j, seen);
        res &= Self::dfs_is_sub(g1, g2, cols, i - 1, j, seen);
        res &= Self::dfs_is_sub(g1, g2, cols, i, j + 1, seen);
        res &= Self::dfs_is_sub(g1, g2, cols, i, j - 1, seen);

        res
    }

    pub fn count_sub_islands(grid1: Vec<Vec<i32>>, grid2: Vec<Vec<i32>>) -> i32 {
        assert!(
            grid1.len() != 0 && grid1.len() == grid2.len() && grid1.len() <= 500 &&
            grid1[0].len() != 0 && grid1[0].len() == grid2[0].len() && grid1[0].len() <= 500
        );

        let (rows, cols) = (grid1.len() as isize, grid1[0].len() as isize);
        let mut seen = vec![false; (rows * cols) as usize];
        let mut cnt = 0_i32;

        for i in 0..rows {
            for j in 0..cols {
                if !seen[(i * cols + j) as usize] && grid2[i as usize][j as usize] == 1 {
                    if Self::dfs_is_sub(&grid1, &grid2, cols, i, j, &mut seen) {
                        cnt += 1;
                    }
                }
            }
        }

        cnt
    }
}
