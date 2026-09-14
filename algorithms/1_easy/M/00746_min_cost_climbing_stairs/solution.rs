impl Solution {
    pub fn min_cost_climbing_stairs(cost: Vec<i32>) -> i32 {
        let (mut prev, mut prev_prev) = (0_i32, 0_i32);

        for c in cost {
            let curr = c + prev.min(prev_prev);
            (prev_prev, prev) = (prev, curr);
        }

        prev.min(prev_prev)
    }
}
