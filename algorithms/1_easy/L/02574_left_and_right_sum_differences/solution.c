static inline int reduce_int(const int *restrict nums, const size_t len, int sum_start) {
    for (size_t i = 0; i < len; i += 1) {
        sum_start += nums[i];
    }

    return sum_start;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* leftRightDifference(const int *restrict nums, const int len, int *restrict return_len) {
    int *restrict res = malloc((size_t)len * sizeof(*res));
    if (res == NULL) {
        *return_len = -1;
        return NULL;
    }

    int suff = reduce_int(nums, (size_t)len, 0);
    int pref = 0;

    for (int i = 0; i < len; i += 1)  {
        suff -= nums[i];
        res[i] = ABS(suff - pref);
        pref += nums[i];
    }

    *return_len = len;
    return res;
}
