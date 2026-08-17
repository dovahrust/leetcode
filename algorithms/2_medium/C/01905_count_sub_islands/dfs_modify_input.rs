impl Solution {
    fn dfs_is_sub(g1: &[Vec<i32>], g2: &mut [Vec<i32>], cols: isize, i: isize, j: isize) -> bool {
        let rows = g1.len() as isize;
        if i < 0 || j < 0 || i >= rows || j >= cols || g2[i as usize][j as usize] == 0 {
            return true;
        }

        let mut res = true;
        g2[i as usize][j as usize] = 0;

        if g1[i as usize][j as usize] == 0 {
            res = false;
        }

        res &= Self::dfs_is_sub(g1, g2, cols, i + 1, j);
        res &= Self::dfs_is_sub(g1, g2, cols, i - 1, j);
        res &= Self::dfs_is_sub(g1, g2, cols, i, j + 1);
        res &= Self::dfs_is_sub(g1, g2, cols, i, j - 1);

        res
    }

    pub fn count_sub_islands(grid1: Vec<Vec<i32>>, mut grid2: Vec<Vec<i32>>) -> i32 {
        assert!(
            grid1.len() != 0 && grid1.len() == grid2.len() && grid1.len() <= 500 &&
            grid1[0].len() != 0 && grid1[0].len() == grid2[0].len() && grid1[0].len() <= 500
        );

        let (rows, cols) = (grid1.len() as isize, grid1[0].len() as isize);
        let mut cnt = 0_i32;

        for i in 0..rows {
            for j in 0..cols {
                if grid2[i as usize][j as usize] == 1 {
                    if Self::dfs_is_sub(&grid1, &mut grid2, cols, i, j) {
                        cnt += 1;
                    }
                }
            }
        }

        cnt
    }
}
