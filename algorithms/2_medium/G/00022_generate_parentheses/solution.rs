impl Solution {
    fn dfs(res: &mut Vec<String>, stack: &mut Vec<u8>, n: i32, open_cnt: i32, close_cnt: i32) {
        if open_cnt == n && close_cnt == n {
            res.push(String::from_utf8(stack.clone()).unwrap());
            return;
        }

        if open_cnt < n {
            stack.push(b'(');
            Self::dfs(res, stack, n, open_cnt + 1, close_cnt);
            stack.pop();
        }

        if close_cnt < open_cnt {
            stack.push(b')');
            Self::dfs(res, stack, n, open_cnt, close_cnt + 1);
            stack.pop();
        }
    }

    pub fn generate_parenthesis(n: i32) -> Vec<String> {
        let mut res: Vec<String> = Vec::new();
        let mut stack: Vec<u8> = Vec::with_capacity((n * 2) as usize);

        Self::dfs(&mut res, &mut stack, n, 0, 0);

        res
    }
}
