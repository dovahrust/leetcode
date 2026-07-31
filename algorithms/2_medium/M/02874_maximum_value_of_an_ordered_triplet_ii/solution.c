static inline int max_int(const int a, const int b) {
    return a > b ? a : b;
}

static inline int64_t max_int64(const int64_t a, const int64_t b) {
    return a > b ? a : b;
}

long long maximumTripletValue(const int* nums, const int len) {
    if (len < 3 || nums == NULL) {
        fprintf(stderr, "invalid input");
        exit(1);
    }

    int diff = nums[0] - nums[1];
    int max = max_int(nums[0], nums[1]);
    int64_t res = INT64_MIN;

    for (int i = 2; i < len; i += 1) {
        res = max_int64(res, (int64_t)diff * nums[i]);
        diff = max_int(diff, max - nums[i]);
        max = max_int(max, nums[i]);
    }

    return max_int64(res, 0LL);
}
