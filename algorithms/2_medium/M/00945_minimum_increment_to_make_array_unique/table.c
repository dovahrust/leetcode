int minIncrementForUnique(const int *restrict nums, const int len) {
    if (nums == NULL || len <= 1) { return 0; }
    if (len > 100000) { return -1; }

    int max = INT_MIN;
    int min = INT_MAX;

    for (int i = 0; i < len; i += 1) {
        max = MAX(max, nums[i]);
        min = MIN(min, nums[i]);
    }

    const size_t width = (size_t)((int64_t)max - min + 1);
    uint32_t *restrict freqs = calloc(width, sizeof(*freqs));
    if (freqs == NULL) { return -1; }

    for (int i = 0; i < len; i += 1) {
        freqs[nums[i] - min] += 1;
    }

    uint32_t res = 0;
    for (size_t i = 0; i < width - 1; i += 1) {
        const uint32_t freq = freqs[i];
        if (freq > 1) {
            res += freq - 1;
            freqs[i] -= freq - 1;
            freqs[i + 1] += freq - 1;
        }
    }

    const uint64_t last = (uint64_t)(freqs[width - 1] - 1);
    res += (uint32_t)(last * (last + 1) / 2);

    free(freqs);
    return (int)res;
}
