int longestSubsequence(const int *restrict nums, const int len) {
    if (len == 0 || nums == NULL) { return 0; }
    int xor = 0;
    int zeros = 0;

    for (int i = 0; i < len; i += 1) {
        xor ^= nums[i];
        if (nums[i] == 0) {
            zeros += 1;
        }
    }

    if (zeros == len) {
        return 0;
    }

    if (xor != 0) {
        return len;
    }

    return len - 1;
}
