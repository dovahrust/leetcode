int minSwaps(const int *restrict nums, const int len) {
    if (nums == NULL || len < 0) { return -1; }

    int ones = 0;

    for (int i = 0; i < len; i += 1) {
        assert(nums[i] == 0 || nums[i] == 1);
        ones += nums[i];
    }

    if (ones <= 1 || (len - ones) <= 1) {
        return 0;
    }

    int freq_window = 0;
    for (int i = len - ones; i < len; i += 1) { freq_window += nums[i]; }

    int need = ones - freq_window;

    for (int i = 0; i < len - 1; i += 1) {
        freq_window += nums[i];
        freq_window -= nums[(len - ones + i) % len];
        need = MIN(need, ones - freq_window);
    }

    return need;
}
