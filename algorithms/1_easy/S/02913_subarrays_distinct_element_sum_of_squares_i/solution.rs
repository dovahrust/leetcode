impl Solution {
    pub fn sum_counts(nums: Vec<i32>) -> i32 {
        let len = nums.len();
        let mut set: std::collections::HashSet<i32> = std::collections::HashSet::new();
        let mut res: usize = 0;
        for i in 0..len {
            set.clear();
            for &num in &nums[i..len] {
                set.insert(num);
                res += set.len().pow(2);
            }
        }
        
        res.try_into().unwrap()
    }
}
