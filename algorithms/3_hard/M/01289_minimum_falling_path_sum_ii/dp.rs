impl Solution {
    #[inline(always)]
    fn calc_min1_min2(arr: &[i32]) -> (i32, i32, usize) {
        let (mut m1, mut m2) = (i32::MAX, i32::MAX);
        let mut m1_idx = 0_usize;

        for (i, &v) in arr.iter().enumerate() {
            if v <= m1 {
                m2 = m1;
                m1_idx = i;
                m1 = v;
            } else if v <= m2 {
                m2 = v;
            }
        }

        (m1, m2, m1_idx)
    }

    pub fn min_falling_path_sum(grid: Vec<Vec<i32>>) -> i32 {
        assert!(grid.len() > 0 && grid.len() == grid[0].len());

        let n = grid[0].len();
        if n == 1 { return grid[0][0]; }
        let mut buff = vec![0_i32; 2 * n];
        let (mut curr, mut prev) = buff.split_at_mut(n);

        for g in grid.into_iter().rev() {
            let (n1, n2, n1_idx) = Self::calc_min1_min2(prev);
            for i in 0..n {
                curr[i] = g[i] + n1;
            }
            curr[n1_idx] = g[n1_idx] + n2;

            (prev, curr) = (curr, prev);
        }

        *prev.into_iter().min().unwrap()
    }
}
