impl Solution {
    pub fn maximum_top(nums: Vec<i32>, k: i32) -> i32 {
        let k = k as usize;

        if nums.is_empty() || (nums.len() == 1 && (k & 1) == 1) { return -1; }

        if nums.len() > 1 && k == 1 { return nums[1]; }

        if k > nums.len() { return *nums.iter().max().unwrap(); }

        let mut res: i32 = -1;
        let mut max: i32 = -1;

        for i in 0..k {
            res = max;
            max = max.max(nums[i]);
        }

        if k < nums.len() {
            res = res.max(nums[k]);
        }

        res
    }
}
