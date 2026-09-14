impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        let (mut prev, mut prev_prev) = (0_i32, 0_i32);

        for num in nums {
            let curr = num + prev_prev;
            prev_prev = prev_prev.max(prev);
            prev = curr;
        }

        prev.max(prev_prev)
    }
}
