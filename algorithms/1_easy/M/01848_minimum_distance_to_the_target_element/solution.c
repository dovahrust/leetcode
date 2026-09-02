int getMinDistance(
    const int *restrict nums, const int len,
    const int target,
    const int start
) {
    if (nums == NULL || len <= 0 || start < 0 || start >= len) { return -1; }

    int lo = start;
    int hi = start;
    while (hi < len || lo >= 0) {
        if (hi < len && nums[hi] == target) {
            return hi - start;
        } else {
            hi += 1;
        }

        if (lo >= 0 && nums[lo] == target) {
            return start - lo;
        } else {
            lo -= 1;
        }
    }

    return -1;
}
