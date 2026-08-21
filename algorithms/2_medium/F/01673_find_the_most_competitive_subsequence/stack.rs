impl Solution {
    pub fn most_competitive(nums: Vec<i32>, k: i32) -> Vec<i32> {
        assert!(k >= 1);
        let len = nums.len();
        let k = k as usize;
        assert!(k <= len);

        let mut stack: Vec<i32> = Vec::with_capacity(k);

        for (i, &num) in nums.iter().enumerate() {
            let remains = len - i;

            while !stack.is_empty() && remains + stack.len() > k && *stack.last().unwrap() > num {
                stack.pop();
            }

            if stack.len() < k {
                stack.push(num);
            }
        }

        stack
    }
}
