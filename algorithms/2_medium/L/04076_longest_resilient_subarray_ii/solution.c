int resilientSubarray(const int *restrict nums, const int len, const int k) {
    int si = 0;
    int prev_rem = -1;
    int longest = 1;
    for (int i = 0; i < len; i += 1) {
        const int curr_rem = nums[i] % k;
        if (curr_rem != prev_rem) {
            prev_rem = curr_rem;
            si = i;
        } else {
            const int width = i - si + 1;
            const int v = (width - 1) * curr_rem;
            if (v % k == 0) {
                longest = MAX(longest, width);
            }
        }
    }

    return longest;
}
