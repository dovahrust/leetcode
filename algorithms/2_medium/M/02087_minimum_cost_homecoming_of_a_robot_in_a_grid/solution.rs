impl Solution {
    pub fn min_cost(start_pos: Vec<i32>, home_pos: Vec<i32>, row_costs: Vec<i32>, col_costs: Vec<i32>) -> i32 {
        let mut cost = 0_i32;
        let (mut x, mut y) = (start_pos[0], start_pos[1]);
        let (hx, hy) = (home_pos[0], home_pos[1]);

        while x != hx {
            x += if x < hx { 1 } else { -1 };
            cost += row_costs[x as usize];
        }

        while y != hy {
            y += if y < hy { 1 } else { -1 };
            cost += col_costs[y as usize];
        }

        cost
    }
}
