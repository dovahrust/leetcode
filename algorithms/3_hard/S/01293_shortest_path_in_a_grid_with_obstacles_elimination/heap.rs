use std::collections::BinaryHeap;
use std::cmp::Reverse;

impl Solution {
    pub fn shortest_path(grid: Vec<Vec<i32>>, k: i32) -> i32 {
        debug_assert!(
            grid.len() >= 1 && grid.len() <= 40 &&
            grid[0].len() >= 1 && grid[0].len() <= 40 && k >= 1
        );

        let (rows, cols) = (grid.len(), grid[0].len());

        if rows == 1 && cols == 1 { return 0; }

        if (k as usize) >= rows + cols - 3 {
            return (rows + cols - 2) as i32;
        }

        let mut dp = vec![-1_i16; rows * cols];
        dp[0] = k as i16;
        let mut heap: BinaryHeap<Reverse<(i16, i16, i16, i16)>> = BinaryHeap::with_capacity(2 * (rows + cols));
        heap.push(Reverse((0, 0, 0, k as i16)));

        while let Some(Reverse((cost, i, j, remain_k))) = heap.pop() {
            if (i as usize) == rows - 1 && (j as usize) == cols - 1 {
                return cost as i32;
            }

            for (dx, dy) in [(1, 0), (-1, 0), (0, 1), (0, -1)] {
                let (ni, nj) = (i + dx, j + dy);
                if ni < 0 || nj < 0 || (ni as usize) >= rows || (nj as usize) >= cols {
                    continue;
                }
                let new_remain_k = remain_k - (grid[ni as usize][nj as usize]) as i16; // Its same as: if grid[ni][nj] == 1 { 1 } else { 0 }
                if dp[(ni as usize) * cols + (nj as usize)] >= new_remain_k {
                    continue;
                }
                dp[(ni as usize) * cols + (nj as usize)] = new_remain_k;
                heap.push(Reverse((cost + 1, ni, nj, new_remain_k)));
            }
        }

        -1
    }
}
