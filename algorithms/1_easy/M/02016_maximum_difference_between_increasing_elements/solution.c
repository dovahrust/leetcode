int maximumDifference(const int *restrict nums, const int len) {
    int max_diff = -1;
    int min = INT_MAX;

    for (int i = 0; i < len; i += 1) {
        if (min >= nums[i]) {
            min = nums[i];
        } else {
            max_diff = MAX(max_diff, nums[i] - min);
        }
    }

    return max_diff;
}
