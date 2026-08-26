impl Solution {
    fn dfs(n: i32, diff: i32, res: &mut Vec<i32>, curr: i32) {
        if (n == 0) {
            res.push(curr);
            return;
        }

        let last = curr % 10;
        if last + diff <= 9 {
            Self::dfs(n - 1, diff, res, (curr * 10) + last + diff);
        }

        if diff != 0 && last - diff >= 0 {
            Self::dfs(n - 1, diff, res, (curr * 10) + last - diff);
        }
    }

    pub fn nums_same_consec_diff(n: i32, k: i32) -> Vec<i32> {
        assert!(n >= 2 && n <= 9 && k >= 0 && k <= 9);
        let mut res: Vec<i32> = Vec::new();

        for i in 1..=9_i32 {
            Self::dfs(n - 1, k, &mut res, i);
        }

        res
    }
}
