impl Solution {
    pub fn max_alternating_sum(nums: Vec<i32>) -> i64 {
        let mut prev_num: i32 = 0;
        let mut curr_sum: i64 = 0;

        for num in nums {
            debug_assert!(num > 0);
            curr_sum += (num as i64 - prev_num as i64).max(0);
            prev_num = num;
        }

        curr_sum
    }
}
