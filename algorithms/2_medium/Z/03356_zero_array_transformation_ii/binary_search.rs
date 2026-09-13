impl Solution {
    #[inline(always)]
    fn is_ok(mid: usize, nums: &[i32], pref: &mut[i32], queries: &[Vec<i32>]) -> bool {
        pref.fill(0);
        for i in 0..=mid {
            let q = &queries[i];
            let (b, e, w) = (q[0], q[1], q[2]);
            pref[b as usize] += w;
            pref[(e + 1) as usize] -= w;
        }

        let len = nums.len();
        let mut balance = 0;
        for i in 0..len {
            balance += pref[i];
            if nums[i] - balance > 0 {
                return false;
            }
        }

        true
    }

    pub fn min_zero_array(nums: Vec<i32>, queries: Vec<Vec<i32>>) -> i32 {
        if nums.iter().all(|&x| x == 0) { return 0; }

        if queries.is_empty() { return -1 ; }

        let queries_len = queries.len() as isize;
        let mut lo = 0_isize;
        let mut hi = queries_len - 1;
        let mut pref = vec![0_i32; nums.len() + 1];
        let mut res: isize = -1;

        while lo <= hi {
            let mid = lo + (hi - lo) / 2;

            if Self::is_ok(mid as usize, &nums, &mut pref, &queries) {
                hi = mid -1;
                res = mid + 1;
            } else {
                lo = mid + 1;
            }
        }

        res.try_into().unwrap()
    }
}
