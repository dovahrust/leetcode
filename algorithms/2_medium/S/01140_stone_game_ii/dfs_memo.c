#define INF INT_MAX

static inline int max_int(const int a, const int b) {
    return a > b ? a : b;
}

static inline int min_int(const int a, const int b) {
    return a < b ? a : b;
}

static int dfs(
    const int *restrict piles, const int len,
    const int idx,
    const int m,
    int *restrict memo
) {
    if (idx == len) {
        return 0;
    }

    const int memo_idx = idx * (len + 1) + m;
    if (memo[memo_idx] != INF) {
        return memo[memo_idx];
    }

    int sum = 0;
    int res = INT_MIN;
    const int end = min_int(len, idx + 2 * m);
    for (int i = idx; i <  end; i += 1) {
        sum += piles[i];
        const int new_m = max_int(m, i - idx + 1);
        res = max_int(res, sum - dfs(piles, len, i + 1, new_m, memo));
    }
    memo[memo_idx] = res;
    return res;
}

int stoneGameII(const int *restrict piles, const int len) {
    if (len < 1 || len > 100 || piles == NULL) {
        fprintf(stderr, "invalid input");
        exit(1);
    }

    int* memo = malloc((size_t)((len + 1) * len) * sizeof(*memo));
    if (memo == NULL) {
        fprintf(stderr, "alloc fail");
        exit(1);
    }
    for (int i = ((len + 1) * len) - 1; i >= 0; i -= 1) { memo[i] = INF; }

    const int diff = dfs(piles, len, 0, 1, memo);
    int sum = 0;
    for (int i = 0; i < len; i += 1) {
        sum += piles[i];
    }

/* cleanup: */
    free(memo);

    // diff = A - B
    // sum = A + B
    // (sum + diff) / 2 = (A+B + A-B)/2 = A.
    return (sum + diff) / 2;
}
