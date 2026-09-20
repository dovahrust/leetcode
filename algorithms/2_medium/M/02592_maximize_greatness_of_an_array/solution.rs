impl Solution {
    pub fn maximize_greatness(mut nums: Vec<i32>) -> i32 {
        nums.sort_unstable();

        let len = nums.len();
        let mut lo: usize = 0;

        for hi in 0..len {
            if nums[hi] > nums[lo] {
                lo += 1;
            }
        }

        lo.try_into().unwrap()
    }
}
