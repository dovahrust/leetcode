impl Solution {
    pub fn left_right_difference(mut nums: Vec<i32>) -> Vec<i32> {
        let mut suff: i32 = nums.iter().sum();
        let mut pref: i32 = 0;

        for num_ref in nums.iter_mut()  {
            let original_val = *num_ref;
            suff -= original_val;
            *num_ref = (suff - pref).abs();
            pref += original_val;
        }

        nums
    }
}
