inline static int max_arr(const int *restrict nums, const size_t len) {
    int max = INT_MIN;
    for (size_t i = 0; i < len; i += 1) {
        max = MAX(max, nums[i]);
    }
    return max;
}

int maximumTop(const int *restrict nums, const int len, const int k) {
    if (len == 0 || nums == NULL || (len == 1 && (k & 1) == 1)) { return -1; }

    if (len > 1 && k == 1) { return nums[1]; }

    if (k > len) { return max_arr(nums, (size_t)len); }

    int res = -1;
    int max = -1;

    for (int i = 0; i < k; i += 1) {
        res = max;
        max = MAX(max, nums[i]);
    }

    if (k < len) {
        res = MAX(res, nums[k]);
    }

    return res;
}
