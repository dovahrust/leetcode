impl Solution {
    pub fn num_subarrays_with_sum(nums: Vec<i32>, goal: i32) -> i32 {
        let len = nums.len();
        let mut res: usize = 0;
        let mut sum: i32 = 0;
        let mut lo: usize = 0;
        let mut mid: usize = 0;

        for hi in 0..len {
            sum += nums[hi];

            if sum > goal {
                sum -= nums[mid];
                lo = mid + 1;
                mid = lo;
            }

            if lo <= hi && sum == goal {
                while mid < hi && nums[mid] == 0 {
                    mid += 1;
                }
                res += mid + 1 - lo;
            }
        }

        res.try_into().unwrap()
    }
}
