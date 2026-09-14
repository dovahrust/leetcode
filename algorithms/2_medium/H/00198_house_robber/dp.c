int rob(const int *restrict nums, const int len) {
    int prev = 0;
    int prev_prev = 0;

    for (int i = 0; i < len; i += 1) {
        const int curr = nums[i] + prev_prev;
        prev_prev = MAX(prev_prev, prev);
        prev = curr;
    }

    return MAX(prev, prev_prev);
}
