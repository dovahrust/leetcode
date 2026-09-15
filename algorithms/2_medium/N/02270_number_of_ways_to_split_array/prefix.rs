impl Solution {
    pub fn ways_to_split_array(nums: Vec<i32>) -> i32 {
        if nums.len() <= 1 { return 0; }

        let len = nums.len();
        let mut suff: i64 = nums.iter().map(|x| *x as i64).sum();
        let mut pref: i64 = 0;
        let mut cnt: usize = 0;

        for &num in &nums[0..(len - 1)] {
            pref += num as i64;
            suff -= num as i64;

            if pref >= suff {
                cnt += 1;
            }
        }

        cnt.try_into().unwrap()
    }
}
