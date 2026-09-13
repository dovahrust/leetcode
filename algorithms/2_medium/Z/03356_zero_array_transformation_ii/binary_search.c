inline static bool is_ok(
    const int mid,
    const int* nums, const int nums_len,
    int *restrict pref,
    int **queries
) {
    for (int i = 0; i <= nums_len; i += 1) { pref[i] = 0; }

    for (int i = 0; i <= mid; i += 1) {
        int *q = queries[i];
        pref[q[0]] += q[2];
        pref[q[1] + 1] -= q[2];
    }

    int balance = 0;
    for (int i = 0; i < nums_len; i += 1) {
        balance += pref[i];
        if (nums[i] - balance > 0) {
            return false;
        }
    }

    return true;
}

inline static bool all_zero(const int *nums, const int len) {
    for (int i = 0; i < len; i += 1) {
        if (nums[i] != 0) {
            return false;
        }
    }
    return true;
}

int minZeroArray(
    const int *nums, const int nums_len,
    int **queries, int queries_len, int *queries_cols_data
) {
    if (all_zero(nums, nums_len)) { return 0; }

    if (queries_len == 0) { return -1 ; }

    int lo = 0;
    int hi = queries_len - 1;
    int *restrict pref = malloc((size_t)(nums_len + 1) * sizeof(*pref));
    if (pref == NULL) { return -2; }
    int res = -1;

    while (lo <= hi) {
        const int mid = lo + (hi - lo) / 2;

        if (is_ok(mid, nums, nums_len, pref, queries)) {
            hi = mid -1;
            res = mid + 1;
        } else {
            lo = mid + 1;
        }
    }

    free(pref);
    return res;
}
