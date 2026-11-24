long long countSubarrays(const int *restrict nums, const int len, const int min_k, const int max_k) {
    int64_t w = 0;
    int64_t res = 0;
    for (int i = 0; i < len; i+= 1) {
        if (nums[i] >= min_k && nums[i] <= max_k) {
            w += 1;
        } else {
            w = 0;
        }

        res += w;
    }

    return res;
}
