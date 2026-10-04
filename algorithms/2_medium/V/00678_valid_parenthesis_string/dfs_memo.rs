impl Solution {
    fn dfs(bytes: &[u8], seen: &mut Vec<Vec<bool>>, idx: usize, balance: isize) -> bool {
        if balance < 0 { return false; }

        if idx == bytes.len() { return balance == 0; }

        if seen[idx][balance as usize] { return false; }

        seen[idx][balance as usize] = true;

        if bytes[idx] == b')' {
            Self::dfs(bytes, seen, idx + 1, balance - 1)
        } else if bytes[idx] == b'(' {
            Self::dfs(bytes, seen, idx + 1, balance + 1)
        } else {
            Self::dfs(bytes, seen, idx + 1, balance - 1) ||
            Self::dfs(bytes, seen, idx + 1, balance) ||
            Self::dfs(bytes, seen, idx + 1, balance + 1)
        }
    }

    pub fn check_valid_string(s: String) -> bool {
        let mut seen = vec![vec![false; s.len() + 1]; s.len() + 1];
        Self::dfs(s.as_bytes(), &mut seen, 0, 0)
    }
}
