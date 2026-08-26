int subarraysDivByK(const int *restrict nums, const int len, const int k) {
    if (k < 2 || k > 10000 || len > 30000 || nums == NULL) { return -1; }

    int *restrict freqs = calloc((size_t)k, sizeof(*freqs));
    if (freqs == NULL) { return -1; }
    int sum = 0;
    freqs[0] = 1;

    for (int i = 0; i < len; i+= 1) {
        sum += nums[i];
        freqs[((sum % k) + k) % k] += 1;
    }

    int res = 0;
    for (int i = 0; i < k; i += 1) {
        res += freqs[i] * (freqs[i] - 1) / 2;
    }

    free(freqs);
    return res;
}
