impl Solution {
    pub fn shadow_pairs(nums: Vec<i32>) -> i64 {
        let mut stack: Vec<(i32, usize)> = Vec::with_capacity(nums.len());
        let mut cnt: usize = 0;

        for num in nums {
            while let Some((top, _)) = stack.last() && *top > num {
                stack.pop();
            }

            if let Some(&(top, prev_num_cnt)) = stack.last() {
                if top == num {
                    cnt += prev_num_cnt;
                    stack.push((num, prev_num_cnt));
                } else {
                    cnt += stack.len();
                    stack.push((num, stack.len()));
                }
            } else {
                stack.push((num, 0));
            }
        }

        cnt.try_into().unwrap()
    }
}
