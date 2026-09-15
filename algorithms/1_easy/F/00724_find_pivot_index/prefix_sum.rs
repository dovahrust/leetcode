impl Solution {
    pub fn pivot_index(nums: Vec<i32>) -> i32 {
        let mut suff: i32 = nums.iter().sum();
        let mut pref: i32 = 0;

        for (i, &num) in nums.iter().enumerate() {
            suff -= num;

            if pref == suff {
                return i.try_into().unwrap();
            }

            pref += num;
        }

        -1
    }
}
