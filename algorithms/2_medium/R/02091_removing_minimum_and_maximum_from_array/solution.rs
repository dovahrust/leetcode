impl Solution {
    pub fn minimum_deletions(nums: Vec<i32>) -> i32 {
        if nums.len() <= 2 { return nums.len() as i32; }

        let len = nums.len();
        let (mut max, mut max_idx) = (nums[0], 0_usize);
        let (mut min, mut min_idx) = (nums[0], 0_usize);

        for i in 1..len {
            let num = nums[i];

            if num > max {
                max = num;
                max_idx = i;
            }

            if num < min {
                min = num;
                min_idx = i;
            }
        }

        let r = max_idx.max(min_idx);
        let l = max_idx.min(min_idx);

        let from_r = len - r;
        let from_l = l + 1;
        let from_mid = r - l;

        (from_l + from_r).min(from_l + from_mid).min(from_mid + from_r).try_into().unwrap()
    }
}
