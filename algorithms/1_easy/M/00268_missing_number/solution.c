int missingNumber(int *restrict nums, const int len) {
    if (nums == NULL || len <= 0) { return -1; }

    for (int i = 0; i < len; i += 1) {
        const int num_as_index = nums[i] < 0 ? ABS(nums[i]) - 1: nums[i];
        assert(num_as_index <= len);

        if (num_as_index != len) {
            nums[num_as_index] = -1 * nums[num_as_index] - 1;
        }
    }

    for (int i = 0; i < len; i += 1) {
        if (nums[i] >= 0) {
            return i;
        }

        i += 1;
    }

    return len;
}
