impl Solution {
    pub fn target_indices(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut start_idx: i32 = 0;
        let mut freq: i32 = 0;

        for num in nums {
            if num < target {
                start_idx += 1;
            } else if num == target {
                freq += 1
            }
        }

        (start_idx..(start_idx + freq)).collect::<Vec<_>>()
    }
}
