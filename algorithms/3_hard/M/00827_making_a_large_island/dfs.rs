impl Solution {
    const NO_REGION: i16 = -1;

    #[inline(always)]
    fn calc_max(regions: &[i16], regions_size: &[i16], i: isize, j: isize, n: isize) -> i16 {
        if regions[(i * n + j) as usize] != Self::NO_REGION {
            return regions_size[regions[(i * n + j) as usize] as usize];
        }

        let mut regs = [0_i16; 4];
        let mut regs_len = 0;
        for (dx, dy) in [(1, 0), (-1, 0), (0, 1), (0, -1)] {
            let (ni, nj) = (i + dx, j + dy);
            if ni < 0 || nj < 0 || ni >= n || nj >= n {
                continue;
            }
            if regions[(ni * n + nj) as usize] != Self::NO_REGION {
                regs[regs_len] = regions[(ni * n + nj) as usize];
                regs_len += 1;
            }
        }

        if regs_len == 0 {
            return 1;
        }

        let mut res = 1_i16;
        regs[0..regs_len].sort();
        res += regions_size[regs[0] as usize];
        for i in 1..regs_len {
            if regs[i] != regs[i - 1] {
                res += regions_size[regs[i] as usize];
            }
        }

        res
    }

    fn dfs(grid: &[Vec<i32>], regions: &mut[i16], region: i16, i: isize, j: isize) -> i16 {
        let n = grid.len() as isize;
        if i < 0 || i >= n || j < 0 || j >= n ||
           regions[(i * n + j) as usize] != Self::NO_REGION ||
           grid[i as usize][j as usize] != 1
        {
            return 0;
        }

        regions[(i * n + j) as usize] = region;

        1 + Self::dfs(grid, regions, region, i + 1, j) +
            Self::dfs(grid, regions, region, i - 1, j) +
            Self::dfs(grid, regions, region, i, j - 1) +
            Self::dfs(grid, regions, region, i, j + 1)
    }

    pub fn largest_island(grid: Vec<Vec<i32>>) -> i32 {
        let n = grid.len();
        assert!(n > 0 && n <= 500 && grid[0].len() == n);
        let mut regions = vec![Self::NO_REGION; n * n];
        let mut regions_size: Vec<i16> = Vec::new();
        for i in 0..n {
            for j in 0..n {
                if grid[i][j] == 1 && regions[i * n + j] == Self::NO_REGION {
                    let reg_size = Self::dfs(&grid, &mut regions, regions_size.len() as i16, i as isize, j as isize);
                    regions_size.push(reg_size);
                }
            }
        }

        let mut max = 0;
        for i in 0..n {
            for j in 0..n {
                max = max.max(Self::calc_max(&regions, &regions_size, i as isize, j as isize, n as isize));
            }
        }

        max as i32
    }
}
