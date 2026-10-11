static int cmp(const void *av, const void *bv) {
    const int *a = *(const int **)av;
    const int *b = *(const int **)bv;

    if (a[0] == b[0]) {
        return (b[1] > a[1]) - (b[1] < a[1]);
    } else {
        return (a[0] > b[0]) - (a[0] < b[0]);
    }
}

int maxEnvelopes(int **envelopes, const int len, int *cols_data) {
    qsort(envelopes, (size_t)len, sizeof(*envelopes), cmp);

    int *restrict lis = malloc((size_t)len * sizeof(*lis));
    if (lis == NULL) { return -1; }
    int lis_len = 0;

    for (int i = 0; i < len; i += 1) {
        int lo = 0;
        int hi = lis_len - 1;
        const int target = envelopes[i][1];

        while (lo <= hi) {
            const int mid = lo + ((hi - lo) >> 1);
            if (lis[mid] >= target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        if (lo == lis_len) {
            lis[lis_len] = target;
            lis_len += 1;
        } else {
            lis[lo] = target;
        }
    }

    return lis_len;
}
