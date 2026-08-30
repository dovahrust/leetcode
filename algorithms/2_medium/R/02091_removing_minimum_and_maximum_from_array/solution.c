int minimumDeletions(const int *restrict nums, const int len) {
    if ((len > 0 && nums == NULL) || len < 0) { return -1; }
    if (len <= 2) { return len; }

    int max = nums[0];
    int max_idx = 0;
    int min = nums[0];
    int min_idx = 0;

    for (int i = 1; i < len; i += 1) {
        const int num = nums[i];

        if (num > max) {
            max = num;
            max_idx = i;
        }

        if (num < min) {
            min = num;
            min_idx = i;
        }
    }

    const int r = MAX(max_idx, min_idx);
    const int l = MIN(max_idx, min_idx);

    const int from_r = len - r;
    const int from_l = l + 1;
    const int from_mid = r - l;

    return MIN(
        from_l + from_r,
        MIN(from_l + from_mid, from_mid + from_r)
    );
}
