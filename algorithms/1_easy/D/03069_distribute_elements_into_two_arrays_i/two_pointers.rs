impl Solution {
    pub fn result_array(nums: Vec<i32>) -> Vec<i32> {
        if nums.len() <= 2 { return nums; }

        let len = nums.len();
        let mut res = vec![0_i32; len];
        let mut hi = len - 1;
        res[hi] = nums[1];
        let mut lo = 0;
        res[lo] = nums[0];

        for i in 2..len {
            if res[hi] > res[lo] {
                hi -= 1;
                res[hi] = nums[i];
            } else {
                lo += 1;
                res[lo] = nums[i];
            }
        }

        res[hi..len].reverse();

        res
    }
}
