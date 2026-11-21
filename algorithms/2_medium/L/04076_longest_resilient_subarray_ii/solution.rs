impl Solution {
    pub fn resilient_subarray(nums: Vec<i32>, k: i32) -> i32 {
        let mut si: usize = 0;
        let mut prev_rem: i32 = -1;
        let mut longest: i32 = 1;
        for (i, num) in nums.into_iter().enumerate() {
            let curr_rem = num % k;
            if curr_rem != prev_rem {
                prev_rem = curr_rem;
                si = i;
            } else {
                let width = (i - si + 1) as i32;
                let v = (width - 1) * curr_rem;
                if v % k == 0 {
                    longest = longest.max(width);
                }
            }
        }

        longest
    }
}
