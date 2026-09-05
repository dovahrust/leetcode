impl Solution {
    pub fn moves_to_make_zigzag(nums: Vec<i32>) -> i32 {
        if nums.len() <= 2 { return 0; }

        let len = nums.len();
        let (mut odd, mut even) = (0_i32, 0_i32);

        for i in (1..len).step_by(2) {
            let prev = nums[i - 1];
            let next = *nums.get(i + 1).unwrap_or(&i32::MAX);
            let target = prev.min(next) - 1;
            odd += std::cmp::max(nums[i] - target, 0);
        }

        for i in (0..len).step_by(2) {
            let prev = *nums.get(i - 1).unwrap_or(&i32::MAX);
            let next = *nums.get(i + 1).unwrap_or(&i32::MAX);
            let target = prev.min(next) - 1;
            even += std::cmp::max(nums[i] - target, 0);
        }

        odd.min(even)
    }
}
