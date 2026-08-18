impl Solution {
    pub fn number_of_weeks(milestones: Vec<i32>) -> i64 {
        if milestones.is_empty() { unreachable!("invalid input"); }

        let mut max = i64::MIN;
        let mut sum = 0;

        for m in milestones {
            if m <= 0 {
                unreachable!("invalid input");
            }
            max = max.max(m as i64);
            sum += m as i64;
        }

        let sum_rest = sum - max;

        sum_rest + max.min(sum_rest + 1)
    }
}
