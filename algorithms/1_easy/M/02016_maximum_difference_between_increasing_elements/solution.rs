impl Solution {
    pub fn maximum_difference(nums: Vec<i32>) -> i32 {
        let mut max_diff: i32 = -1;
        let mut min: i32 = i32::MAX;

        for num in nums {
            if min >= num {
                min = num;
            } else {
                max_diff = max_diff.max(num - min);
            }
        }

        max_diff
    }
}
