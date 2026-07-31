static int cmp(const void* a_ptr, const void* b_ptr) {
    const int a = *(int*)a_ptr;
    const int b = *(int*)b_ptr;
    return (a > b) - (a < b);
}

static inline bool is_ok(const int *restrict prices, const int len, int k, const int mid) {
    k -= 1;
    int curr = prices[0];

    for (int i = 1; i < len; i += 1) {
        if (prices[i] - curr >= mid) {
            k -= 1;
            curr = prices[i];

            if (k == 0) {
                return true;
            }
        }
    }

    return false;
}

int maximumTastiness(int* prices, const int len, const int k) {
    if (k < 2 || k > len || len > 100000) {
        fprintf(stderr, "invalid input");
        return -1;
    }

    int lo = 0;
    int hi = INT_MAX;
    qsort(prices, (size_t)len, sizeof(*prices), cmp);

    while (lo <= hi) {
        const int mid = lo + (hi - lo) / 2;
        if (is_ok(prices, len, k, mid)) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    return hi;
}
