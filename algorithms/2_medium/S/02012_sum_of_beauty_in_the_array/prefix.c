 __attribute__((no_sanitize("all")))
int sumOfBeauties(const int *restrict nums, const int len) {
    if (len <= 2 || nums == NULL) { return 0; }

    int *restrict min_right = malloc((size_t)len * sizeof(*min_right));
    if (min_right == NULL) { return -1; }
    min_right[len - 1] = nums[len - 1];
    for (int i = len - 2; i >= 0; i -= 1) {
        min_right[i] = MIN(nums[i], min_right[i + 1]);
    }

    int res = 0;
    int max_left = nums[0];

    for (int i = 1; i < len -1; i += 1) {
        if (max_left < nums[i] && nums[i] < min_right[i + 1]) {
            res += 2;
        } else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
            res += 1;
        }

        max_left = MAX(max_left, nums[i]);
    }

    free(min_right);
    return res;
}
