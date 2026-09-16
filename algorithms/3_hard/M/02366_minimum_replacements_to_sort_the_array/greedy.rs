impl Solution {
    pub fn minimum_replacement(nums: Vec<i32>) -> i64 {
        let mut min = i32::MAX;
        let mut cnt: i64 = 0;

        for num in nums.into_iter().rev() {
            if num <= min {
                min = num;
            } else {
                let parts = (num + min - 1) / min;
                min = num / parts;
                cnt += (parts - 1) as i64;
            }
        }

        cnt
    }
}
