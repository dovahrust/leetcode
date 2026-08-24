impl Solution {
    pub fn find_diagonal_order(nums: Vec<Vec<i32>>) -> Vec<i32> {
        let rows = nums.len();
        let mut max_col = 0_usize;
        let mut total_element = 0_usize;
        
        for num in &nums {
            max_col = max_col.max(num.len());
            total_element += num.len();
        }

        assert!(rows <= 100_000 && total_element <= 100_000 && max_col <= 100_000);

        let mut stacks: Vec<Vec<i32>> = vec![vec![]; rows + max_col];

        for (i, num) in nums.into_iter().enumerate() {
            for (j, val) in num.into_iter().enumerate() {
                stacks[i + j].push(val);
            }
        }

        let mut res: Vec<i32> = Vec::with_capacity(total_element);

        for stack in stacks {
            for val in stack.into_iter().rev() {
                res.push(val);
            }
        }

        res
    }
}
