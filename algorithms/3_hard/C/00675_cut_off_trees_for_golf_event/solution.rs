use std::collections::VecDeque;

#[derive(Eq, PartialEq, Clone, Copy)]
enum State {
    CanNotBeVisited,
    Visited,
    NotVisited,
}

impl Solution {
    const DIRECTIONS: [(isize, isize); 4] = [(1, 0), (-1, 0), (0, 1), (0, -1)];

    fn dfs(grid: &mut [State], rows: isize, cols: isize, i: isize, j: isize) {
        if i >= rows || i < 0 || j >= cols || j < 0 || grid[(i * cols + j) as usize] != State::NotVisited { return; }

        grid[(i * cols + j) as usize] = State::Visited;

        for (dx, dy) in Self::DIRECTIONS {
            Self::dfs(grid, rows, cols, i + dx, j + dy);
        }
    }

    fn is_bad(grid: &mut [State], rows: isize, cols: isize) -> bool {
        Self::dfs(grid, rows, cols, 0, 0);
        grid.iter().any(|x| *x == State::NotVisited)
    }

    #[inline(always)]
    fn calc_dist(
        q: &mut VecDeque<(isize, isize)>,
        grid: &mut [State], rows: isize, cols: isize,
        si: isize, sj: isize,
        di: isize, dj: isize
    ) -> isize {
        grid.iter_mut().for_each(|x| if *x == State::Visited {
                *x = State::NotVisited;
        });

        q.clear();
        q.push_back((si, sj));
        grid[(si * cols + sj) as usize] = State::Visited;
        let mut steps: isize = 0;
        while !q.is_empty() {
            let q_len = q.len();

            for _ in 0..q_len {
                let (i, j) = q.pop_front().unwrap();
                if i == di && j == dj {
                    return steps;
                }

                for (dx, dy) in Self::DIRECTIONS {
                    let (ni, nj) = (i + dx, j + dy);
                    if ni < 0 || ni >= rows || nj < 0 || nj >= cols || grid[(ni * cols + nj) as usize] != State::NotVisited { continue; }

                    grid[(ni * cols + nj) as usize] = State::Visited;
                    q.push_back((ni, nj));
                }
            }

            steps += 1;
        }

        unreachable!("logic error")
    }

    pub fn cut_off_tree(forest: Vec<Vec<i32>>) -> i32 {
        let rows = forest.len() as isize;
        let cols = forest[0].len() as isize;
        let mut grid = vec![State::CanNotBeVisited; (rows * cols) as usize];

        for i in 0..rows {
            for j in 0..cols {
                if forest[i as usize][j as usize] != 0 {
                    grid[(i * cols + j) as usize] = State::NotVisited;
                }
            }
        }

        if Self::is_bad(&mut grid, rows, cols) { return -1; }

        let mut trees: Vec<(i32, isize, isize)> = Vec::new();

        for i in 0..rows {
            for j in 0..cols {
                if forest[i as usize][j as usize] > 1 {
                    trees.push((forest[i as usize][j as usize], i, j))
                }
            }
        }

        trees.sort_unstable();
        let (mut si, mut sj): (isize, isize) = (0, 0);
        let mut q: VecDeque<(isize, isize)> = VecDeque::with_capacity(grid.len());
        let mut res: isize = 0;

        for (_, ti, tj) in trees {
            let dist = Self::calc_dist(&mut q, &mut grid, rows, cols, si, sj, ti, tj);
            (si, sj) = (ti, tj);
            res += dist; 
        }

        res as i32
    }
}
