impl Solution {
    pub fn grid_game(grid: Vec<Vec<i32>>) -> i64 {
        assert!(grid.len() == 2);
        let cols = grid[0].len();
        if cols <= 1 { return 0; }

        let mut u: i64 = grid[0].iter().skip(1).map(|&x| x as i64).sum();
        let mut d = 0_i64;
        let mut res = u;
        for j in 1..cols {
            u -= grid[0][j] as i64;
            d += grid[1][j - 1] as i64;
            res = res.min(u.max(d));
        }

        res
    }
}
