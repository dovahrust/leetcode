const INVALID_CHAR: char = '#';

impl Solution {
    fn dfs(
        board: &mut [Vec<char>],
        cols: isize,
        i: isize,
        j: isize,
        word: &[u8],
        word_idx: usize,
    ) -> bool {
        if word_idx == word.len() {
            return true;
        }

        let rows = board.len() as isize;
        if i < 0 || i >= rows || j < 0 || j >= cols || board[i as usize][j as usize] != word[word_idx] as char {
            return false;
        }

        let orig = board[i as usize][j as usize];
        board[i as usize][j as usize] = INVALID_CHAR;

        let res = Self::dfs(board, cols, i + 1, j, word, word_idx + 1) ||
                  Self::dfs(board, cols, i - 1, j, word, word_idx + 1) ||
                  Self::dfs(board, cols, i, j + 1, word, word_idx + 1) ||
                  Self::dfs(board, cols, i, j - 1, word, word_idx + 1);

        board[i as usize][j as usize] = orig;
 
        res
    }

    pub fn exist(mut board: Vec<Vec<char>>, word_string: String) -> bool {
        let rows = board.len() as isize;
        let cols = board[0].len() as isize;
        let word_bytes = word_string.as_bytes();

        for i in 0..rows {
            for j in 0..cols {
                if Self::dfs(&mut board, cols, i, j, word_bytes, 0) {
                    return true;
                }
            }
        }

        false
    }
}
