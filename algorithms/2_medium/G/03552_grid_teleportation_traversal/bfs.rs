use std::collections::VecDeque;

impl Solution {
    #[inline(always)]
    fn push_neighbors_to_q(
        q: &mut VecDeque<(i16, i16)>,
        costs: &mut[i32],
        mat: &[String],
        cols: usize,
        i: i16,
        j: i16,
        level: i32
    ) {
        let rows = mat.len();
        for (dx, dy) in [(0, 1), (1, 0), (-1, 0), (0, -1)] {
            let (ni, nj) = (i + dx, j + dy);
            if ni < 0 || nj < 0 {
                continue;
            }
            let (ni, nj) = (ni as usize, nj as usize);
            if ni >= rows || nj >= cols || mat[ni].as_bytes()[nj] == b'#' {
                continue;
            }
            if costs[ni * cols + nj] > level + 1 {
                costs[ni * cols + nj] = level + 1;
                q.push_back((ni as i16, nj as i16));
            }
        }
    }

    pub fn min_moves(matrix: Vec<String>) -> i32 {
        assert!(matrix.len() > 0 && matrix[0].len() > 0);
        let (rows, cols) = (matrix.len(), matrix[0].len());
        assert!(rows <= 1000 && cols <= 1000);

        let mut teleports = vec![Vec::<(i16, i16)>::new(); 26];
        for (i, m) in matrix.iter().enumerate() {
            for (j, &b) in m.as_bytes().into_iter().enumerate() {
                match b {
                    b'A'..=b'Z' => teleports[(b - b'A') as usize].push((i as i16, j as i16)),
                    b'#' | b'.' => {},
                    _ => unreachable!(),
                }
            }
        }

        let mut q: VecDeque<(i16, i16)> = VecDeque::with_capacity(2 * (rows + cols));
        q.push_back((0, 0));
        let mut level = 0;
        let mut costs = vec![i32::MAX; rows * cols];

        while !q.is_empty() {
            let q_len = q.len();
            for _ in 0..q_len {
                let ((i, j)) = q.pop_front().unwrap();

                if (i as usize) == rows - 1 && (j as usize) == cols - 1 {
                    return level;
                }

                let curr = matrix[i as usize].as_bytes()[j as usize];
                if curr >= b'A' && curr <= b'Z' {
                    if curr == matrix[rows - 1].as_bytes()[cols - 1] {
                        return level;
                    }

                    for &(ti, tj) in &teleports[(curr - b'A') as usize] {
                        Self::push_neighbors_to_q(&mut q, &mut costs, &matrix, cols, ti, tj, level);
                    }
                    teleports[(curr - b'A') as usize].clear();
                } else {
                    Self::push_neighbors_to_q(&mut q, &mut costs, &matrix, cols, i, j, level);
                }
            }

            level += 1;
        }

        -1
    }
}
