inline static bool is_ok(const int *nums1, const int *nums2, const int n, const int mid, int total_change) {
    for (int i = 0; i < n; i += 1) {
        const int diff = ABS(nums1[i] - nums2[i]);
        if (diff > mid) {
            total_change -= diff - mid;

            if (total_change < 0) { return false; }
        }
    }
    return true;
}

inline static int calc_hi(const int *nums1, const int *nums2, const int n) {
    int max = 0;
    for (int i = 0; i < n; i += 1) {
        max = MAX(max, ABS(nums1[i] - nums2[i]));
    }
    return max;
}

long long minSumSquareDiff(const int *nums1, const int nums1_len, const int *nums2, const int nums_len, const int k1, const int k2) {
    const int n = nums1_len;
    int lo = 0;
    int hi = calc_hi(nums1, nums2, n);
    const int total_change = k1 + k2;

    while (lo <= hi) {
        const int mid = lo + (hi - lo) / 2;

        if (is_ok(nums1, nums2, n, mid, total_change)) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    if (lo == 0) { return 0; }

    int total_use = 0;
    for (int i = 0; i < n; i += 1) {
        const int diff = ABS(nums1[i] - nums2[i]);
        total_use += MAX(0, diff - lo);
    }

    int64_t res = 0;
    for (int i = 0; i < n; i += 1) {
        int diff = MIN(lo, ABS(nums1[i] - nums2[i]));
        if (diff == lo && total_use < total_change) {
            diff -= 1;
            total_use += 1;
        }
        res += (int64_t)diff * (int64_t)diff;
    }

    return res;
}
