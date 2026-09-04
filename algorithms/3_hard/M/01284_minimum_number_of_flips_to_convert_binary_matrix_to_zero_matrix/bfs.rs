use std::collections::VecDeque;

impl Solution {
    const DIRS: [(isize, isize); 4] = [(-1, 0), (1, 0), (0, 1), (0, -1)];

    pub fn min_flips(mat: Vec<Vec<i32>>) -> i32 {
        assert!(
            mat.len() >= 1 && mat.len() <= 3 &&
            mat[0].len() >= 1 && mat[0].len() <= 3
        );

        let init_mask = Self::calc_mask_mat(&mat);
        if init_mask == 0 { return 0; }

        let (rows, cols) = (mat.len(), mat[0].len());
        let flips_masks = Self::calc_flip_mask(rows, cols);
        let total_items = rows * cols;
        let mut seen = vec![false; 1_usize << total_items];
        let mut q: VecDeque<u16> = VecDeque::new();
        seen[init_mask as usize] = true;
        q.push_back(init_mask);
        let mut level = 0_i32;

        while !q.is_empty() {
            let q_len = q.len();
            for _ in 0..q_len {
                let curr = q.pop_front().unwrap();
                for i in 0..rows {
                    for j in 0..cols {
                        for &fm in &flips_masks {
                            let next = curr ^ fm;
                            if next == 0 {
                                return level + 1;
                            }
                            if !seen[next as usize] {
                                seen[next as usize] = true;
                                q.push_back(next);
                            }
                        }
                    }
                }
            }
            level += 1;
        }
        
        -1
    }

    #[inline(always)]
    fn calc_flip_mask(rows: usize, cols: usize) -> Vec<u16> {
        let mut res: Vec<u16> = Vec::with_capacity(rows * cols);
        for i in 0..rows {
            for j in 0..cols {
                let mut mask = 0_u16;
                mask |= (1_u16 << (i * cols + j) as u16);
                for (dx, dy) in Self::DIRS {
                    let (ni, nj) = (dx + i as isize, dy + j as isize);
                    if ni < 0 || nj < 0 { continue; }
                    let (ni, nj) = (ni as usize, nj as usize);
                    if ni >= rows || nj >= cols { continue; }

                    mask |= (1_u16 << (ni * cols + nj) as u16);;
                }
                res.push(mask);
            }
        }
        res
    }

    #[inline(always)]
    fn calc_mask_mat(mat: &[Vec<i32>]) -> u16 {
        let (rows, cols) = (mat.len(), mat[0].len());
        let mut mask = 0_u16;
        for i in 0..rows {
            for j in 0..cols {
                if mat[i][j] == 1 {
                    let shift_amount = ((i * cols) + j) as u16;
                    mask |= (1_u16 << shift_amount);
                }
            }
        }
        mask
    }
}
