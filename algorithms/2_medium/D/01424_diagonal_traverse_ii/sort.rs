impl Solution {
    pub fn find_diagonal_order(nums: Vec<Vec<i32>>) -> Vec<i32> {
        let total_element = nums.iter().map(|row| row.len()).sum::<usize>();
        assert!(nums.len() <= 100_000 && total_element <= 100_000);

        let mut arr: Vec<(u32, u32, i32)> = Vec::with_capacity(total_element);
        for (i, num) in nums.into_iter().enumerate() {
            for (j, val) in num.into_iter().enumerate() {
                arr.push(((i + j) as u32, j as u32, val));
            }
        }

        arr.sort_unstable();

        arr.into_iter().map(|(_, _, val)| val).collect()
    }
}
