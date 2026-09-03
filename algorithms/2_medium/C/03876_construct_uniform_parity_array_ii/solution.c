bool uniformArray(const int *restrict nums1, const int len) {
    assert(nums1 != NULL && len > 0);

    int min = INT_MAX;
    bool has_odd = false;

    for (int i = 0; i < len; i += 1) {
        min = MIN(min, nums1[i]);
        if ((nums1[i] & 1) == 1) {
            has_odd = true;
        }
    }

    if ((min & 1) == 0 && has_odd) {
        return false;
    }

    return true;
}
