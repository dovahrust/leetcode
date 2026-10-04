use std::collections::HashMap;

impl Solution {
    fn fix_rows(matrix: &[Vec<i32>], cols: usize, target: i32) -> i32 {
        let rows = matrix.len();
        let mut hashmap: HashMap<i32, i32> = HashMap::with_capacity(2 * cols);
        let mut count: i32 = 0;
        for i_st in 0..rows {
            for i_en in i_st..rows {
                hashmap.clear();
                hashmap.insert(0, 1);
                let mut sum: i32 = 0;
                for j in 0..cols {
                    let sum = matrix[i_en][j] - if i_st > 0 { matrix[i_st - 1][j] } else { 0 };

                    if let Some(&val) = hashmap.get(&(sum - target)) {
                        count += val;
                    }

                    *hashmap.entry(sum).or_insert(0) += 1;
                }
            }
        }

        count
    }

    fn fix_cols(matrix: &[Vec<i32>], cols: usize, target: i32) -> i32 {
        let rows = matrix.len();
        let mut hashmap: HashMap<i32, i32> = HashMap::with_capacity(2 * rows);
        let mut count: i32 = 0;
        for j_st in 0..cols {
            for j_en in j_st..cols {
                hashmap.clear();
                hashmap.insert(0, 1);
                let mut sum: i32 = 0;
                for i in 0..rows {
                    let sum = matrix[i][j_en] - if j_st > 0 { matrix[i][j_st - 1] } else { 0 };

                    if let Some(&val) = hashmap.get(&(sum - target)) {
                        count += val;
                    }

                    *hashmap.entry(sum).or_insert(0) += 1;
                }
            }
        }

        count
    }

    pub fn num_submatrix_sum_target(mut matrix: Vec<Vec<i32>>, target: i32) -> i32 {
        let rows = matrix.len();
        let cols = matrix[0].len();

        for i in 0..rows {
            for j in 1..cols {
                matrix[i][j] += matrix[i][j - 1];
            }
        }

        for j in 0..cols {
            for i in 1..rows {            
                matrix[i][j] += matrix[i - 1][j];
            }
        }

        if rows < cols {
            Self::fix_rows(&matrix, cols, target)
        } else {
            Self::fix_cols(&matrix, cols, target)
        }
    }
}
