const INVALID_CHAR: char = '#';

struct Node {
    childs: [isize; 26],
    is_end: bool,
    is_deleted: bool,
}

impl Node {
    fn new() -> Self {
        Self {
            childs: [-1; 26],
            is_end: false,
            is_deleted: false,
        }
    }
}

struct Trie {
    arr: Vec<Node>,
}

impl Trie {
    #[inline(always)]
    fn init_freqs_board(freqs: &mut [usize], board: &[Vec<char>]) {
        for r in board {
            for &c in r {
                if (c as u8) < b'a' || (c as u8) > b'z' {
                    panic!("invalid input");
                }
                freqs[((c as u8) - b'a') as usize] += 1;
            }
        }
    }

    #[inline(always)]
    fn init_adj_board(adj: &mut [usize], board: &[Vec<char>]) {
        let rows = board.len();
        let cols = board[0].len();
        for i in 0..rows {
            for j in 0..cols {
                let curr = ((board[i][j] as u8) - b'a') as usize;
                if i > 0 {
                    let up = ((board[i - 1][j] as u8) - b'a') as usize;
                    adj[up * 26 + curr] += 1;
                    if up != curr { adj[curr * 26 + up] += 1; }
                }

                if j > 0 {
                    let le = ((board[i][j - 1] as u8) - b'a') as usize;
                    adj[le * 26 + curr] += 1;
                    if le != curr { adj[curr * 26 + le] += 1; } 
                }
            }
        }
    }

    fn from_string_slices(words: &[String], board: &[Vec<char>]) -> Self {
        let mut freqs_board = [0_usize; 26];
        Self::init_freqs_board(&mut freqs_board, board);
        let mut adj_board = [0_usize; 26 * 26];
        Self::init_adj_board(&mut adj_board, board);

        let mut arr: Vec<Node> = Vec::new();
        arr.push(Node::new());
        'main_loop: for word in words {
            let mut freqs_word = [0_usize; 26];
            for &b in word.as_bytes() {
                if b < b'a' || b > b'z' {
                    panic!("invalid input");
                }
                freqs_word[(b - b'a') as usize] += 1;
                if freqs_word[(b - b'a') as usize] > freqs_board[(b - b'a') as usize] {
                    continue 'main_loop;
                }
            }

            let mut adj_word = [0_usize; 26 * 26];
            for w in word.as_bytes().windows(2) {
                let a = (w[0] - b'a') as usize;
                let b = (w[1] - b'a') as usize;
                adj_word[a * 26 + b] += 1;
                if a != b {
                    adj_word[b * 26 + a] += 1;
                }
                if adj_word[a * 26 + b] > adj_board[a * 26 + b] {
                    continue 'main_loop;
                }
            }
            
            let mut curr = 0_usize;
            for &b in word.as_bytes() {
                let child_idx = (b - b'a') as usize;
                if arr[curr].childs[child_idx] == -1 {
                    arr[curr].childs[child_idx] = arr.len() as isize;
                    arr.push(Node::new());
                }
                curr = arr[curr].childs[child_idx] as usize;
            }
            arr[curr].is_end = true;
        }

        Self {
            arr,
        }
    }

    #[inline(always)]
    fn mark_node_deleted_if_possible(&mut self, node_idx: usize) -> bool {
        if self.arr[node_idx].is_end { return false; }

        for &c in &self.arr[node_idx].childs {
            if c != -1 && !self.arr[c as usize].is_deleted {
                return false;
            }
        }

        self.arr[node_idx].is_deleted = true;
        true
    }

    fn dfs(
        &mut self,
        trie_idx: usize,
        board: &mut [Vec<char>],
        cols: isize,
        i: isize,
        j: isize,
        tmp: &mut Vec<u8>,
        res: &mut Vec<String>,
    ) {
        if self.arr[trie_idx].is_deleted { return; }

        if self.arr[trie_idx].is_end {
            self.arr[trie_idx].is_end = false;
            res.push(String::from_utf8_lossy(tmp).into_owned());
            if self.mark_node_deleted_if_possible(trie_idx) { return; }
        }

        let rows = board.len() as isize;
        if i < 0 || i >= rows || j < 0 || j >= cols || board[i as usize][j as usize] == INVALID_CHAR {
            return;
        }

        let orig = board[i as usize][j as usize];
        let new_trie_idx_isize = self.arr[trie_idx].childs[((orig as u8) - b'a') as usize];
        if new_trie_idx_isize == -1 {
            return;
        }

        let new_trie_idx = new_trie_idx_isize as usize;
        board[i as usize][j as usize] = INVALID_CHAR;
        tmp.push(orig as u8);

        self.dfs(new_trie_idx, board, cols, i + 1, j, tmp, res);
        self.dfs(new_trie_idx, board, cols, i - 1, j, tmp, res);
        self.dfs(new_trie_idx, board, cols, i, j + 1, tmp, res);
        self.dfs(new_trie_idx, board, cols, i, j - 1, tmp, res);
        let _ = self.mark_node_deleted_if_possible(new_trie_idx);

        tmp.pop();
        board[i as usize][j as usize] = orig;
    }

    #[inline(always)]
    pub fn run(board: &mut [Vec<char>], words: &[String]) -> Vec<String> {
        let rows = board.len() as isize;
        let cols = board[0].len() as isize;
        let mut trie = Self::from_string_slices(words, board);
        let mut tmp: Vec<u8> = Vec::new();
        let mut res: Vec<String> = Vec::new();

        'main_loop: for i in 0..rows {
            for j in 0..cols {
                trie.dfs(0, board, cols, i, j, &mut tmp, &mut res);
                if trie.mark_node_deleted_if_possible(0) { break 'main_loop; }
            }
        }

        res
    }
}

impl Solution {
    pub fn find_words(mut board: Vec<Vec<char>>, words: Vec<String>) -> Vec<String> {
        Trie::run(&mut board, &words)
    }
}
