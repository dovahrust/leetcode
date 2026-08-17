impl Solution {
    pub fn rotate_grid(grid: Vec<Vec<i32>>, k: i32) -> Vec<Vec<i32>> {
        assert!(k >= 1 && grid.len() > 0 && grid[0].len() > 0);
        let rows = grid.len();
        let cols = grid[0].len();
        let k = k as usize;
        assert!((rows & 1) == 0 && (cols & 1) == 0);

        let mut res = vec![vec![0_i32; cols]; rows];
        let mut buff = Vec::with_capacity(2 * (rows + cols));

        let (mut i_lo, mut i_hi): (usize, usize) = (0, rows - 1);
        let (mut j_lo, mut j_hi): (usize, usize) = (0, cols - 1);

        while i_lo < i_hi && j_lo < j_hi {
            buff.clear();
            for i in i_lo..=i_hi {
                buff.push(grid[i][j_lo]);
            }
            for j in (j_lo + 1)..=j_hi {
                buff.push(grid[i_hi][j]);
            }
            for i in (i_lo..=(i_hi - 1)).rev() {
                buff.push(grid[i][j_hi]);
            }
            for j in ((j_lo + 1)..=(j_hi - 1)).rev() {
                buff.push(grid[i_lo][j]);
            }
            let need = buff.len() - (k % buff.len());
            buff.rotate_left(need);
            let mut idx = 0_usize;
            for i in i_lo..=i_hi {
                res[i][j_lo] = buff[idx];
                idx += 1;
            }
            for j in (j_lo + 1)..=j_hi {
                res[i_hi][j] = buff[idx];
                idx += 1;
            }
            for i in (i_lo..=(i_hi - 1)).rev() {
                res[i][j_hi] = buff[idx];
                idx += 1;
            }
            for j in ((j_lo + 1)..=(j_hi - 1)).rev() {
                res[i_lo][j] = buff[idx];
                idx += 1;
            }
            i_lo += 1;
            i_hi -= 1;
            j_lo += 1;
            j_hi -= 1;
        }

        res
    }
}
