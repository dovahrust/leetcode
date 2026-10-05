impl Solution {
    pub fn num_special(mat: Vec<Vec<i32>>) -> i32 {
        let rows = mat.len();
        let cols = mat[0].len();
        let mut buff = vec![0_i32; rows + cols];
        let (mut rows_sum, mut cols_sum) = buff.split_at_mut(rows);

        for i in 0..rows {
            for j in 0..cols {
                rows_sum[i] += mat[i][j];
                cols_sum[j] += mat[i][j];
            }
        }

        let mut cnt: i32 = 0;
        for i in 0..rows {
            for j in 0..cols {
                if mat[i][j] == 1 && rows_sum[i] == 1 && cols_sum[j] == 1 {
                    cnt += 1;
                }
            }
        }

        cnt
    }
}
