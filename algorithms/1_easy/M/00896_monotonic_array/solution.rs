impl Solution {
    pub fn is_monotonic(nums: Vec<i32>) -> bool {
        if nums.len() <= 1 {
            return true;
        }

        let len = nums.len();
        let mut state = 0_i32;

        for i in 1..len {
            if nums[i] > nums[i - 1] {
                if state == -1 { 
                    return false;
                }
                state = 1;
            } else if nums[i] < nums[i - 1] {
                if state == 1 {
                    return false;
                }
                state = -1;
            }
        }

        true
    }
}
