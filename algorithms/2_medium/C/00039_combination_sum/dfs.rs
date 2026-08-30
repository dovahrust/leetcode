impl Solution {
    fn dfs(
        candidates: &[i32],
        idx: usize,
        target: i32,
        res: &mut Vec<Vec<i32>>,
        tmp: &mut Vec<i32>,
    ) {
        if target == 0 {
            res.push(tmp.clone());
            return;
        }

        if target < 0 || idx >= candidates.len() {
            return;
        }

        tmp.push(candidates[idx]);
        Self::dfs(candidates, idx, target - candidates[idx], res, tmp);
        tmp.pop();

        Self::dfs(candidates, idx + 1, target, res, tmp);
    }

    pub fn combination_sum(candidates: Vec<i32>, target: i32) -> Vec<Vec<i32>> {
        let mut res: Vec<Vec<i32>> = Vec::new();
        let mut tmp: Vec<i32> = Vec::new();

        Self::dfs(&candidates, 0, target, &mut res, &mut tmp);

        res
    }
}
