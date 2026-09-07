impl Solution {
    pub fn count_good_rotations(nums: Vec<i32>) -> i32 {
        assert!((nums.len() & 1) == 0 && nums.len() > 0);
        let len = nums.len();
        let half = len / 2;
        let full_sum = nums.iter().map(|&x| x as i64).sum::<i64>();
        let mut window_sum = nums[half..len].iter().map(|&x| x as i64).sum::<i64>();
        let mut cnt = if 2 * window_sum > full_sum { 1 } else { 0 };

        for i in 0..(len - 1) {
            window_sum -= nums[(i + len - half) % len] as i64;
            window_sum += nums[i] as i64;
            if 2 * window_sum > full_sum { 
                cnt += 1;
            }
        }

        cnt
    }
}
