impl Solution {
    pub fn peak_valley_difference(nums: Vec<i32>) -> i32 {
        let len = nums.len();
        if len <= 2 { return 0; }

        let mut res: i32 = 0;

        for w in nums.windows(3) {
            if w[0] < w[1] && w[1] > w[2] {
                res += w[1];
            } else if w[0] > w[1] && w[1] < w[2] {
                res -= w[1];
            }
        }

        res
    }
}
