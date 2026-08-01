int smallestBalancedIndex(const int* nums, const int len) {
    int64_t sum_pref = 0;
    for (int i = 0; i < len; i += 1) {
        assert(nums[i] > 0);
        sum_pref += nums[i];
    }

    int64_t mul_suff = 1;
    for (int i = len - 1; i >= 0; i -= 1) {
        sum_pref -= nums[i];

        if (sum_pref == mul_suff) {
            return i;
        } else if (mul_suff > sum_pref) {
            return -1;
        }

        if (__builtin_mul_overflow(mul_suff, (int64_t)nums[i], &mul_suff)) {
            return -1;
        }
    }

    return -1;
}
