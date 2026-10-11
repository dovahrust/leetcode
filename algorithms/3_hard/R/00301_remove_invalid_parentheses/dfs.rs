use std::collections::HashSet;

impl Solution {
    fn calc_valid_pairs_cnt(bytes: &[u8]) -> usize {
        let mut pair_cnt: usize = 0;
        let mut open_cnt: usize = 0;

        for &b in bytes {
            match b {
                b'(' => open_cnt += 1,
                b')' => {
                    if open_cnt > 0 {
                        open_cnt -= 1;
                        pair_cnt += 1;
                    }
                },
                _ => {},
            }
        }

        pair_cnt
    }

    fn dfs(
        bytes: &[u8], idx: usize,
        valid_pairs: usize,
        open_use: usize,
        close_use: usize,
        stack: &mut Vec<u8>, 
        res: &mut HashSet<String>
    ) {
        if open_use > valid_pairs { return; }

        if idx == bytes.len() {
            if open_use == valid_pairs && close_use == valid_pairs {
                res.insert(String::from_utf8_lossy(stack).into_owned());
            }

            return;
        }

        match bytes[idx] {
            b'(' => {
                stack.push(b'(');
                Self::dfs(bytes, idx + 1, valid_pairs, open_use + 1, close_use, stack, res);
                stack.pop();

                Self::dfs(bytes, idx + 1, valid_pairs, open_use, close_use, stack, res);
            },
            b')' => {
                if close_use < open_use {
                    stack.push(b')');
                    Self::dfs(bytes, idx + 1, valid_pairs, open_use, close_use + 1, stack, res);
                    stack.pop();
                }

                Self::dfs(bytes, idx + 1, valid_pairs, open_use, close_use, stack, res);
            },
            _ => {
                stack.push(bytes[idx]);
                Self::dfs(bytes, idx + 1, valid_pairs, open_use, close_use, stack, res);
                stack.pop();
            }
        }
    }

    pub fn remove_invalid_parentheses(s: String) -> Vec<String> {
        let valid_pairs = Self::calc_valid_pairs_cnt(s.as_bytes());
        let mut res: HashSet<String> = HashSet::new();
        let mut stack: Vec<u8> = Vec::with_capacity(s.len());

        Self::dfs(s.as_bytes(), 0, valid_pairs, 0, 0, &mut stack, &mut res);

        res.into_iter().collect()
    }
}
