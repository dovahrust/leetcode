int countGoodRotations(const int *restrict nums, const int len) {
    if (len <= 0 || (len & 1) == 1 || nums == NULL) { return -1; }

    const int half = len / 2;

    int64_t full_sum = 0;
    for (int i = 0; i < len; i += 1) { full_sum += nums[i]; }

    int64_t window_sum = 0;
    for (int i = half; i < len; i += 1) { window_sum += nums[i]; }

    int cnt = (2 * window_sum > full_sum ? 1 : 0);

    for (int i = 0; i < len - 1; i += 1) {
        window_sum -= nums[(i + len - half) % len];
        window_sum += nums[i];
        if (2 * window_sum > full_sum) {
            cnt += 1;
        }
    }

    return cnt;
}
