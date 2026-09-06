use std::collections::VecDeque;

impl Solution {
    const WATER: char = '0';
    const LAND: char = '1';
    const LAND_VISITED: char = '2';
    const DIRS: [(isize, isize); 4] = [(0, 1), (0, -1), (1, 0), (-1, 0)];

    pub fn num_islands(mut grid: Vec<Vec<char>>) -> i32 {
        let (rows, cols) = (grid.len(), grid[0].len());
        let mut q: VecDeque<(usize, usize)> = VecDeque::new();
        let mut cnt = 0_i32;    

        for r in 0..rows {
            for c in 0..cols {
                if grid[r][c] == Self::LAND {
                    cnt += 1;
                    q.push_back((r, c));

                    while let Some((i, j)) = q.pop_front() {
                        for (dx, dy) in Self::DIRS {
                            let ni = i as isize + dx;
                            let nj = j as isize + dy;

                            if ni < 0 || nj < 0 { continue; }

                            let (ni, nj) = (ni as usize, nj as usize);

                            if ni >= rows || nj >= cols || grid[ni][nj] != Self::LAND { continue; }

                            grid[ni][nj] = Self::LAND_VISITED;
                            q.push_back((ni, nj));
                        }
                    }
                }
            }
        }

        cnt
    }
}
