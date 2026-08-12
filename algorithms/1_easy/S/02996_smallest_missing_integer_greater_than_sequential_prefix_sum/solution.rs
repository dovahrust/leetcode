const MAX_NUM: i32 = 50;
const MIN_NUM: i32 = 1;

impl Solution {
    pub fn missing_integer(nums: Vec<i32>) -> i32 {
        assert!(!nums.is_empty() && nums[0] >= MIN_NUM && nums[0] <= MAX_NUM);
        let len = nums.len();

        let mut seen = [false; MAX_NUM as usize + 2];
        for &num in &nums {
            assert!(num >= MIN_NUM && num <= MAX_NUM);
            seen[num as usize] = true;
        }

        let mut prefix = nums[0];
        let mut i = 1_usize;
        while i < len && nums[i] == nums[i - 1] + 1 {
            prefix += nums[i];
            i += 1;
        }

        if prefix > MAX_NUM {
            return prefix;
        }

        for i in prefix..MAX_NUM + 2 {
            if !seen[i as usize] {
                return i;
            }
        }

        unreachable!()
    }
}
