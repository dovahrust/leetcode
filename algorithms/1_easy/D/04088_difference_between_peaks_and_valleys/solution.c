int peakValleyDifference(const int *restrict nums, const int len) {
    if (len <= 2) { return 0; }

    int res = 0;

    for (int i = 1; i + 1 < len; i += 1) {
        if (nums[i - 1] < nums[i] && nums[i] > nums[i + 1]) {
            res += nums[i];
        } else if (nums[i - 1] > nums[i] && nums[i] < nums[i + 1]) {
            res -= nums[i];
        }
    }

    return res;
}
