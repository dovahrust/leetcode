impl Solution {
    pub fn find_middle_index(nums: Vec<i32>) -> i32 {
        let mut suff: i32 = nums.iter().sum();
        let mut pref: i32 = 0;
        let len = nums.len();

        for i in 0..len {
            suff -= nums[i];

            if suff == pref {
                return i.try_into().unwrap();
            }

            pref += nums[i];
        }

        -1
    }
}
