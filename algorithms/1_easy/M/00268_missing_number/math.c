int missingNumber(const int *restrict nums, const int len) {
    if (nums == NULL || len <= 0) { return -1; }

    int sum = 0;

    for (int i = 0; i < len; i += 1) {
        sum += nums[i];
    }

    const int target_sum = (len * (len + 1)) / 2;
    return target_sum - sum;
}
