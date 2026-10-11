impl Solution {
    pub fn sum_of_squares(nums: Vec<i32>) -> i32 {
        let mut res = 0;
        let len = nums.len();
        let sqrt_len = len.isqrt();
        for i in 1..=sqrt_len {
            if (len % i) == 0 {
                let other_idx = len / i;
                res += nums[i - 1].pow(2);
                if other_idx != i {
                    res += nums[other_idx - 1].pow(2);
                }
            }
        }

        res
    }
}
