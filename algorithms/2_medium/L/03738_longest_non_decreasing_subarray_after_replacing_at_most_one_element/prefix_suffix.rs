impl Solution {
    pub fn longest_subarray(nums: Vec<i32>) -> i32 {
        let len = nums.len();
        assert!(len <= 100_000);
        if len <= 2 { return len as i32; }

        let mut buff: Vec<(i32, i32)> = vec![(0, 0); len];

        let mut prefix_cnt = 0_i32;
        let mut prev_val = 0_i32;
        for i in 0..len {
            let num = nums[i];
            if prev_val <= num {
                prefix_cnt += 1;
            } else {
                prefix_cnt = 1;
            }
            prev_val = num;
            buff[i].0 = prefix_cnt;
        }

        let mut suffix_cnt = 0_i32;
        let mut next_val = 0_i32;
        for i in (0..len).rev() {
            let num = nums[i];
            if num <= next_val {
                suffix_cnt += 1;
            } else {
                suffix_cnt = 1;
            }
            next_val = num;
            buff[i].1 = suffix_cnt;
        }

        let mut res = 0_i32;
        for i in 1..(len - 1) {
            if nums[i - 1] <= nums[i + 1] {
                let pref = buff[i - 1].0;
                let suff = buff[i + 1].1;
                res = res.max(1 + pref + suff);
            } else {
                res = res.max(1 + buff[i].0).max(1 + buff[i].1);
            }
        }

        res
    }
}
