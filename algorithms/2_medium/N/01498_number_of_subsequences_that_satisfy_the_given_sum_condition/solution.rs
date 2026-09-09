impl Solution {
    const MOD: isize = 1_000_000_007;

    #[inline(always)]
    fn pow_with_mod<const MOD: isize>(mut base: isize, mut pow: isize) -> isize {
        let mut res = 1_isize;
        while pow > 0 {
            if (pow & 1) == 1 {
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            pow >>= 1;
        }
        res
    }

    pub fn num_subseq(mut nums: Vec<i32>, target: i32) -> i32 {
        if nums.is_empty() { return 0; }

        nums.sort_unstable();
        let len = nums.len();
        let mut cnt = 0_isize;
        let mut lo = 0_isize;
        let mut hi = len as isize - 1;

        while lo <= hi {
            if nums[lo as usize] + nums[hi as usize] > target {
                hi -= 1;
            } else {
                cnt = (cnt + Self::pow_with_mod::<{ Self::MOD }>(2, hi - lo)) % Self::MOD;
                lo += 1;
            }
        }

        cnt as i32
    }
}
