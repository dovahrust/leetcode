impl Solution {
    pub fn num_subarray_product_less_than_k(nums: Vec<i32>, k: i32) -> i32 {
        assert!(k >= 0 && k <= 1_000_000);

        if k <= 1 { return 0; }

        let len = nums.len();
        let mut lo = 0_usize;
        let mut prod = 1_i32;
        let mut cnt = 0_usize;

        for hi in 0..len {
            assert!(nums[hi] >= 1 && nums[hi] <= 1000);
            prod *= nums[hi];

            while prod >= k {
                prod /= nums[lo];
                lo += 1;
            }

            cnt += (hi + 1) - lo;
        }

        cnt.try_into().unwrap()
    }
}
