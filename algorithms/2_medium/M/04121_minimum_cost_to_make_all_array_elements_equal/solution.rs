impl Solution {
    pub fn min_cost(nums: Vec<i32>) -> i64 {
        let len = nums.len();
        let mut i: usize = 0;
        let mut cost = i64::MAX;

        while i < len {
            let mut j = i;
            while j + 1 < len && nums[j + 1] == nums[i] { j += 1; }

            let cost_pref = (i as i64) * (nums[i] as i64);
            let cost_suff = ((len - j - 1) as i64) * (nums[i] as i64);

            if j != 0 && i != len - 1 { cost = cost.min(cost_pref + cost_suff); }

            i = j + 1;
        }

        cost
    }
}
