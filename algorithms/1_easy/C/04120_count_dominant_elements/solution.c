int countDominantElements(const int *restrict nums, const int len) {
    if (len <= 1) { return len; }

    int cnt = 0;

    if (nums[0] >= nums[1]) { cnt += 1; }

    if (nums[len - 2] <= nums[len - 1]) { cnt += 1; }

    for (int i = 1; i < len - 1; i += 1) {
        if (2 * nums[i] >= nums[i - 1] + nums[i + 1]) { cnt += 1; }
    }

    return cnt;
}
