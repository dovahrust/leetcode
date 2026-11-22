int minMergedInteger(const int *restrict nums, const int len) {
    assert((len & 1) == 0);
    int min = INT_MAX;
    for (int i = 0; i < len; i += 2) {
        int tmp = nums[i + 1];
        int mul = 1;
        while (tmp > 0) {
            mul *= 10;
            tmp /= 10;
        }
        const int merg = nums[i] * mul + nums[i + 1];
        min = MIN(min, merg);
    }

    return min;
}
