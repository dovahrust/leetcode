use std::collections::VecDeque;

impl Solution {
    pub fn color_grid(n: i32, m: i32, sources: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let (n, m) = (n as isize, m as isize);
        let mut res = vec![vec![-1_i32; m as usize]; n as usize];
        let mut states = vec![isize::MAX; (m * n) as usize];
        let mut q: VecDeque<(isize, isize)> = VecDeque::with_capacity((m * n) as usize);
        let mut steps: isize = 0;

        for s in sources {
            let (i, j, c) = (s[0] as isize, s[1] as isize, s[2]);
            res[i as usize][j as usize] = c;
            states[(i * m + j) as usize] = steps;
            q.push_back((i, j));
        }

        while !q.is_empty() {
            steps += 1;
            let q_len = q.len();
            for _ in 0..q_len {
                let ((i, j)) = q.pop_front().unwrap();
                for (dx, dy) in [(1, 0), (0, 1), (-1, 0), (0, -1)] {
                    let (ni, nj) = (i + dx, j + dy);
                    if ni < 0 || ni >= n || nj < 0 || nj >= m { continue; }

                    if states[(ni * m + nj) as usize] < steps { continue; }

                    res[ni as usize][nj as usize] = res[ni as usize][nj as usize].max(res[i as usize][j as usize]);

                    if states[(ni * m + nj) as usize] > steps {
                        states[(ni * m + nj) as usize] = steps;
                        q.push_back((ni, nj));
                    }
                }
            }
        }

        res
    }
}
