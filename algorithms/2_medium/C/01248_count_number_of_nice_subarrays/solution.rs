impl Solution {
    pub fn number_of_subarrays(nums: Vec<i32>, k: i32) -> i32 {
        let len = nums.len();
        let mut odd_cnt: i32 = 0;
        let mut lo: usize = 0;
        let mut mid: usize = 0;
        let mut res: usize = 0;

        for hi in 0..len {
            if (nums[hi] & 1) == 1 { odd_cnt += 1; }

            if odd_cnt > k {
                odd_cnt = k;
                mid += 1;
                lo = mid;
            }

            if odd_cnt == k {
                while (nums[mid] & 1) == 0 {
                    mid += 1;
                }
                res += mid - lo + 1;
            }
        }

        res.try_into().unwrap()
    }
}
