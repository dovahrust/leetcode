inline static int groups_state(const int *restrict arr, const int len, const int val, const int target) {
    int cnt = 0;
    for (int i = 0; i < len; i += 1) {
        cnt +=  (arr[i] + val - 1) / val;
        if (cnt > target) {
            return 1;
        }
    }

    return cnt == len ? 0 : -1;
}

int minimizedMaximum(const int n, const int *restrict quantities, const int quantities_len) {
    assert(n >= quantities_len && quantities_len > 0);

    int lo = 1;
    int hi = INT_MAX;

    while (lo <= hi) {
        const int mid = lo + (hi - lo) / 2;
        switch (groups_state(quantities, quantities_len, mid, n)) {
            case 1:
                lo = mid + 1;
                break;
            default:
                hi = mid - 1;
                break;
        }
    }

    return lo;
}
