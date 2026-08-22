int numSubarrayProductLessThanK(const int *restrict nums, const int len, const int k) {
    assert(k >= 0 && k <= 1000000);

    if (k <= 1) { return 0; }

    int lo = 0;
    int prod = 1;
    int cnt = 0;

    for (int hi = 0; hi < len; hi += 1) {
        assert(nums[hi] >= 1 && nums[hi] <= 1000);
        prod *= nums[hi];

        while (prod >= k) {
            prod /= nums[lo];
            lo += 1;
        }

        cnt += (hi + 1) - lo;
    }

    return cnt;
}
