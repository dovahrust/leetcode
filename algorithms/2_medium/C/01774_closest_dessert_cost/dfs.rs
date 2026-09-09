impl Solution {
    #[inline(always)]
    fn is_curr_better(curr: i32, target: i32, res: i32) -> bool {
        (curr - target).abs() < (res - target).abs() ||
        ((curr - target).abs() == (res - target).abs() && curr < res)
    }

    fn dfs(costs: &[i32], idx: usize, curr: i32, target: i32, res: &mut i32) {
        if Self::is_curr_better(curr, target, *res) {
            *res= curr;
        } else if curr > target {
            return;
        }

        if idx == costs.len() {
            return;
        }

        Self::dfs(costs, idx + 1, curr, target, res);
        Self::dfs(costs, idx + 1, curr + costs[idx], target, res);
        Self::dfs(costs, idx + 1, curr + (2 * costs[idx]), target, res);
    }

    pub fn closest_cost(base_costs: Vec<i32>, topping_costs: Vec<i32>, target: i32) -> i32 {
        let mut res = i32::MAX;

        for base in base_costs {
            Self::dfs(&topping_costs, 0, base, target, &mut res);
        }

        res
    }
}
