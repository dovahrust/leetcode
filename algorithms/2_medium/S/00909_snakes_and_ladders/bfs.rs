use std::collections::VecDeque;

impl Solution {
    fn make_board_flat(board: Vec<Vec<i32>>) -> Vec<i32> {
        let n = board.len();
        let mut flat_board: Vec<i32> = Vec::with_capacity((n * n) + 1);
        flat_board.push(-2); // cell 0 doesnt exist;
        let mut flip_flop = true;
        for b in board.into_iter().rev() {
            if flip_flop {
                for val in b {
                    flat_board.push(val);
                }
            } else {
                for val in b.into_iter().rev() {
                    flat_board.push(val);
                }
            }
            flip_flop = !flip_flop;
        }
        assert!(flat_board[1] == -1 && flat_board[n * n] == -1);

        flat_board
    }

    pub fn snakes_and_ladders(board: Vec<Vec<i32>>) -> i32 {
        let n = board.len();
        assert!(n >= 2 && n <= 20 && board[0].len() == n);
        let flat_board = Self::make_board_flat(board);

        let target = (n * n) as i32;
        let mut q: VecDeque<i32> = VecDeque::with_capacity(2 * n);
        q.push_back(1);
        let mut seen = vec![false; (n * n) + 1];
        seen[1] = true;
        let mut rolls = 1;

        while !q.is_empty() {
            let q_len = q.len();

            for _ in 0..q_len {
                let node = q.pop_front().unwrap();

                for step in 1..=6 {
                    let mut curr = node + step;

                    if flat_board[curr as usize] != -1 && curr != flat_board[curr as usize] {
                        curr = flat_board[curr as usize];
                    }

                    if curr == target {
                        return rolls;
                    }

                    if !seen[curr as usize] {
                        seen[curr as usize] = true;
                        q.push_back(curr);
                    }
                }
            }

            rolls += 1;
        }

        -1
    }
}
