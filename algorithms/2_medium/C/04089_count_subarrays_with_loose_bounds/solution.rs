impl Solution {
    pub fn count_subarrays(nums: Vec<i32>, min_k: i32, max_k: i32) -> i64 {
        let len = nums.len();
        let mut w: i64 = 0;
        let mut res: i64 = 0;
        for num in nums {
            if num >= min_k && num <= max_k { 
                w += 1;
            } else {
                w = 0;
            }

            res += w;
        }

        res
    }
}
