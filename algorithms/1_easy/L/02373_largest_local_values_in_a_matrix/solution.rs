impl Solution {
    pub fn largest_local(grid: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let n = grid.len();
        assert!(n >= 3 && n == grid[0].len());
        let mut res: Vec<Vec<i32>> = Vec::with_capacity(n - 2);

        for i in 0..(n - 2) {
            let mut tmp: Vec<i32> = Vec::with_capacity(n - 2);

            for j in 0..(n - 2) {
                let mut max = i32::MIN;
                for ofs_i in 0..3 {
                    for ofs_j in 0..3 {
                        max = max.max(grid[i + ofs_i][j + ofs_j]);
                    }
                }
                tmp.push(max);
            }

            res.push(tmp);
        }

        res
    }
}
