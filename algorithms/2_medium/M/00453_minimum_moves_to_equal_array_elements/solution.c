int minMoves(const int *restrict nums, const int len) {
    int min = INT_MAX;
    for (int i = 0; i < len; i += 1) { min = MIN(min, nums[i]); }

    int cnt = 0;
    for (int i = 0; i < len; i += 1) { cnt += nums[i] - min; }

    return cnt;
}
