impl Solution {
    pub fn count_servers(grid: Vec<Vec<i32>>) -> i32 {
        let rows = grid.len();
        assert!(rows >= 1 && rows <= 250);
        let cols = grid[0].len();
        assert!(cols >= 1 && cols <= 250);

        let mut buff = vec![0_i32; rows + cols];
        let (mut sum_rows, mut sum_cols) = buff.split_at_mut(rows);
        let mut total = 0_i32;

        for i in 0..rows {
            for j in 0..cols {
                if grid[i][j] == 1 {
                    total += 1;
                    sum_rows[i] += 1;
                    sum_cols[j] += 1;
                }
            }
        }

        for i in 0..rows {
            for j in 0..cols {
                if grid[i][j] == 1 && sum_rows[i] == 1 && sum_cols[j] == 1 {
                    total -= 1;
                }
            }
        }

        total
    }
}
