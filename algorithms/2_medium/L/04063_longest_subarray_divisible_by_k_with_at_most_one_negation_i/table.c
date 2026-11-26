int longestSubarray(const int *restrict nums, const int len, const int k) {
    uint8_t *restrict set = calloc((size_t)k, sizeof(*set));
    uint8_t stamp = 0;
    int max = 0;

    for (int i = 0; i < len; i += 1) {
        if (stamp == UINT8_MAX) {
            stamp = 1;
            for (int j = 0; j < k; j += 1) { set[j] = 0; }
        } else {
            stamp += 1;
        }

        int sum_mod = 0;
        for (int j = i; j < len; j += 1) {
            const int mod_by_k = ((nums[j] % k) + k) % k;
            sum_mod = (sum_mod + mod_by_k) % k;

            if (mod_by_k != 0) {
                const int mod_by_k_comp = k - mod_by_k;
                set[((mod_by_k - mod_by_k_comp + k) % k)] = stamp;
            }

            if (sum_mod == 0 || set[sum_mod] == stamp) {
                max = MAX(max, j - i + 1);
            }
        }
    }

    free(set);
    return max;
}
