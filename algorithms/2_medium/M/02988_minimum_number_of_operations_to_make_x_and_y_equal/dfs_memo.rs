impl Solution {
    fn dfs(x: i32, y: i32, memo: &mut[i32]) -> i32 {
        if x <= y {
            return y - x;
        }

        if memo[x as usize] != -1 {
            return memo[x as usize];
        }

        let mut res = x - y;
        if x % 5 == 0 {
            res = res.min(1 + Self::dfs(x / 5, y, memo));
        } else {
            let diff = x % 5;
            res = res.min(1 + diff + Self::dfs(x / 5, y, memo))
                     .min(1 + 5 - diff + Self::dfs(1 + (x / 5), y, memo));
        }

        if x % 11 == 0 {
            res = res.min(1 + Self::dfs(x / 11, y, memo));
        } else {
            let diff = x % 11;
            res = res.min(1 + diff + Self::dfs(x / 11, y, memo))
                     .min(1 + 11 - diff + Self::dfs(1 + (x / 11), y, memo));
        }

        memo[x as usize] = res;
        res
    }

    pub fn minimum_operations_to_make_equal(x: i32, y: i32) -> i32 {
        assert!(x <= 10_000 && x >= 1 && y >= 1 && y <= 10_000);
        if x <= y {
            return y - x;
        }

        let mut memo = vec![-1_i32; x as usize + 1];

        Self::dfs(x, y, &mut memo)
    }
}
