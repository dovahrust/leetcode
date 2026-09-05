int movesToMakeZigzag(const int *restrict nums, const int len) {
    if (nums == NULL || len <= 2) { return 0; }

    int odd = 0;
    int even = 0;

    for (int i = 1; i < len; i += 2) {
        const int prev = nums[i - 1];
        const int next = i + 1 < len ? nums[i + 1] : INT_MAX;
        const int target = MIN(prev, next) - 1;
        odd += MAX(nums[i] - target, 0);
    }

    for (int i = 0; i < len; i += 2) {
        const int prev = i - 1 >= 0  ? nums[i - 1] : INT_MAX;
        const int next = i + 1 < len ? nums[i + 1] : INT_MAX;
        const int target = MIN(prev, next) - 1;
        even += MAX(nums[i] - target, 0);
    }

    return MIN(odd, even);
}
