impl Solution {
    #[inline(always)]
    fn is_ok(nums1: &[i32], nums2: &[i32], mid: i32, mut total_change: i32) -> bool {
        let n = nums1.len();
        for i in 0..n {
            let diff = (nums1[i] - nums2[i]).abs();
            if diff > mid {
                total_change -= diff - mid;

                if total_change < 0 { return false; }
            }
        }
        true
    }

    pub fn min_sum_square_diff(nums1: Vec<i32>, nums2: Vec<i32>, k1: i32, k2: i32) -> i64 {
        let n = nums1.len();
        let mut lo: i32 = 0;
        let mut hi: i32 = (0..n).into_iter().map(|i| (nums1[i] - nums2[i]).abs()).max().unwrap();
        let total_change = k1 + k2;

        while lo <= hi {
            let mid = lo + (hi - lo) / 2;

            if Self::is_ok(&nums1, &nums2, mid, total_change) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        if lo == 0 { return 0; }

        let mut total_use: i32 = 0;
        for i in 0..n {
            let diff = (nums1[i] - nums2[i]).abs();
            total_use += (diff - lo).max(0);
        }

        let mut res: i64 = 0;
        for i in 0..n {
            let mut diff = (nums1[i] - nums2[i]).abs().min(lo);
            if diff == lo && total_use < total_change {
                diff -= 1;
                total_use += 1;
            }
            res += (diff as i64).pow(2);
        }

        res
    }
}
