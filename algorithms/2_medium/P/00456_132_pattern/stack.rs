impl Solution {
    pub fn find132pattern(nums: Vec<i32>) -> bool {
        let mut stack: Vec<i32> = Vec::with_capacity(nums.len());
        let mut third = i32::MIN;

        for num in nums.into_iter().rev() {
            if num < third {
                return true;
            }

            while let Some(val) = stack.last() && num > *val {
                third = third.max(*val);
                stack.pop();
            }

            stack.push(num);
        }

        false
    }
}
