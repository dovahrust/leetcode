impl Solution {
    pub fn max_points(points: Vec<Vec<i32>>) -> i64 {
        assert!(!points.is_empty() &&!points[0].is_empty());
        let (rows, cols) = (points.len(), points[0].len());
        let mut buff = vec![0_i64; 2 * cols];
        let (mut prev, mut curr) = buff.split_at_mut(cols);

        for i in 0..rows {
            let mut curr_max = 0_i64;
            for j in 0..cols {
                debug_assert!(points[i][j] >= 0 && points[i][j] <= 100_000);
                curr_max -= 1;
                curr_max = curr_max.max(prev[j]);
                curr[j] = curr_max + points[i][j] as i64;
            }

            curr_max = 0;
            for j in (0..cols).rev() {
                curr_max -= 1;
                curr_max = curr_max.max(prev[j]);
                curr[j] = curr[j].max(curr_max + points[i][j] as i64);
            }

            (prev, curr) = (curr, prev);
        }

        *prev.iter().max().unwrap()
    }
}
