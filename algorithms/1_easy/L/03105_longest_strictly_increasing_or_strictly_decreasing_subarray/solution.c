enum states {
    DEC,
    NEU,
    INC
};

int longestMonotonicSubarray(const int *restrict nums, const int len) {
    if (len <= 0 || nums == NULL) { return -1; }

    int longest = 1;
    int curr = 0;
    enum states state = NEU;

    for (int i = 1; i < len; i += 1) {
        if (nums[i] > nums[i - 1]) {
            if (state != INC) {
                curr = 2;
                state = INC;
            } else {
                curr += 1;
            }
        } else if (nums[i] < nums[i - 1]) {
            if (state != DEC) {
                curr = 2;
                state = DEC;
            } else {
                curr += 1;
            }
        } else {
            state = NEU;
            curr = 1;
        }

        longest = MAX(longest, curr);
    }

    return longest;
}
