impl Solution {
    const MAX_NUM: i32 = 15;
    const MOD: i32 = 1_000_000_007;

    pub fn count_paths_with_xor_value(grid: Vec<Vec<i32>>, k: i32) -> i32 {
        assert!(grid.len() > 0 && grid[0].len() > 0 && k >= 0 && k <= Self::MAX_NUM);

        let (rows, cols) = (grid.len(), grid[0].len());

        let mut buff = vec![0_i32; 2 * cols * (Self::MAX_NUM as usize + 1)];
        let (mut prev, mut curr) = buff.split_at_mut(cols * (Self::MAX_NUM as usize + 1));

        let mut xor = 0_i32;
        for (j, &v) in grid[0].iter().enumerate() {
            debug_assert!(v >= 0 && v <= Self::MAX_NUM);
            xor ^= v;
            prev[j * (Self::MAX_NUM as usize + 1) + xor as usize] = 1;
        }

        for line in grid.iter().skip(1) {
            for (j, &v) in line.iter().enumerate() {
                debug_assert!(v >= 0 && v <= Self::MAX_NUM);
                for prev_val in 0..=Self::MAX_NUM  {
                    let curr_idx = j * (Self::MAX_NUM as usize + 1) + (prev_val ^ v) as usize;
                    let up_idx = j * (Self::MAX_NUM as usize + 1) + prev_val as usize;

                    curr[curr_idx] = prev[up_idx];
                }

                if j > 0 {
                    for prev_val in 0..=Self::MAX_NUM  {
                        let curr_idx = j * (Self::MAX_NUM as usize + 1) + (prev_val ^ v) as usize;
                        let left_idx = (j - 1) * (Self::MAX_NUM as usize + 1) + prev_val as usize;

                        curr[curr_idx] = (curr[curr_idx] + curr[left_idx]) % Self::MOD;
                    }
                }
            }

            (prev, curr) = (curr, prev);
            curr.iter_mut().for_each(|x| *x = 0);
        }

        let target_idx = (cols - 1) * (Self::MAX_NUM as usize + 1) + k as usize;
        prev[target_idx]
    }
}
