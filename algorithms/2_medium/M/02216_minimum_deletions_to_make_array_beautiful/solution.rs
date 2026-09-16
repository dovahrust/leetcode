impl Solution {
    pub fn min_deletion(nums: Vec<i32>) -> i32 {
        if nums.len() <= 1 { return nums.len() as i32; }

        let len = nums.len();
        let mut cnt: usize = 1;
        let mut lo: usize = 0;
        let mut hi: usize = 1;

        for hi in 1..len {
            if ((cnt - 1) & 1) == 0 {
                if nums[lo] != nums[hi] {
                    lo = hi;
                    cnt += 1;
                }
            } else {
                lo = hi;
                cnt += 1;
            }
        }

        if (cnt & 1) == 1 {
            cnt -= 1;
        }

        (len - cnt).try_into().unwrap()
    }
}
