impl Solution {
    pub fn max_product(nums: Vec<i32>) -> i32 {
        assert!(nums.len() >= 2);
        let mut max1 = i32::MIN;
        let mut max2 = i32::MIN;

        for &num in nums.iter() {
            if num >= max1 {
                max2 = max1;
                max1 = num;
            } else if num >= max2 {
                max2 = num;
            }
        }

        (max1 - 1) * (max2 - 1)
    }
}
