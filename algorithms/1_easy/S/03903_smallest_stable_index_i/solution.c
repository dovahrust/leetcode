int firstStableIndex(const int *restrict nums, const int len, const int k) {
    assert(len > 0 && nums != NULL && k >= 0);
    if (len == 1) { return 0; }

    int *restrict mins = malloc((size_t)len * sizeof(*mins));
    assert(mins != NULL);
    mins[len - 1] = nums[len - 1];
    for (int i = len - 2; i >= 0; i -= 1) {
        mins[i] = MIN(nums[i], mins[i + 1]);
    }

    int max = INT_MIN;
    int res = -1;
    for (int i = 0; i < len; i += 1) {
        max = MAX(max, nums[i]);
        if (max - mins[i] <= k) {
            res = i;
            break;
        }
    }

    free(mins);
    return res;
}
