impl Solution {
    pub fn get_min_distance(nums: Vec<i32>, target: i32, start: i32) -> i32 {
        let len = nums.len() as isize;
        let start = start as isize;

        if nums.is_empty() || start < 0 || start >= len { return -1; }


        let mut lo = start;
        let mut hi = start;
        while hi < len || lo >= 0 {
            if hi < len && nums[hi as usize] == target {
                return (hi - start).try_into().unwrap();
            } else {
                hi += 1;
            }

            if (lo >= 0 && nums[lo as usize] == target) {
                return (start - lo).try_into().unwrap();
            } else {
                lo -= 1;
            }
        }

        -1
    }
}
