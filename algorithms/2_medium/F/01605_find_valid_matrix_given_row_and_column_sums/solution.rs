impl Solution {
    pub fn restore_matrix(row_sum: Vec<i32>, mut col_sum: Vec<i32>) -> Vec<Vec<i32>> {
        let rows = row_sum.len();
        let cols = col_sum.len();

        let mut res: Vec<Vec<i32>> = vec![vec![0; cols]; rows];

        for i in 0..rows {
            let mut curr_row_sum = row_sum[i];
            for j in 0..cols {
                let val = col_sum[j].min(curr_row_sum);
                col_sum[j] -= val;
                curr_row_sum -= val;
                res[i][j] = val;

                if curr_row_sum == 0 {
                    break;
                }
            }
        }

        res
    }
}
