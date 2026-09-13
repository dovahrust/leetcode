struct pair {
    int val;
    int idx;
};

static int cmp(const void *a_ptr, const void *b_ptr) {
    const struct pair a = *(struct pair*)a_ptr;
    const struct pair b = *(struct pair*)b_ptr;

    return (a.val < b.val) - (a.val > b.val);
}

int maxJumps(const int *restrict arr, const int len, const int d) {
    if (d < 0) { return -1; }

    int *restrict dp = malloc((size_t)len * sizeof(*dp));
    if (dp == NULL) { return -1; }

    struct pair *restrict combo = malloc((size_t)len * sizeof(*combo));
    if (combo == NULL) {
        free(dp);
        return -1;
    }

    for (int i = 0; i < len; i += 1) {
        combo[i].val = arr[i];
        combo[i].idx = i;
        dp[i] = 1;
    }
    qsort(combo, (size_t)len, sizeof(*combo), cmp);

    for (int i = 0; i < len; i +=1) {
        const int curr_h = combo[i].val;
        const int idx = combo[i].idx;
        const int curr_dp = dp[idx];

        for (int j = idx + 1; j <= idx + d && j < len; j += 1) {
            if (arr[j] >= curr_h) { break; }

            dp[j] = MAX(dp[j], curr_dp + 1);
        }

        for (int j = idx - 1; j >= idx - d && j >= 0; j -= 1) {
            if (arr[j] >= curr_h) { break; }

            dp[j] = MAX(dp[j], curr_dp + 1);
        }
    }

    int res = 0;
    for (int i = 0; i < len; i += 1) {
        res = MAX(res, dp[i]);
    }

    free(dp);
    free(combo);
    return res;
}
