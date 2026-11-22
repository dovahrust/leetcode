int minMoves(const int *restrict nums, const int len) {
    int max = INT_MIN;
    int res = 0;

    for (int i = 0; i < len; i += 1) { max = MAX(max, nums[i]); }

    for (int i = 0; i < len; i += 1) { res += max - nums[i]; }

    return res;
}
