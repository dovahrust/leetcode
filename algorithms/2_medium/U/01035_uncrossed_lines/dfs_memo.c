static int dfs(
    const int *restrict n1, const size_t n1_len, const size_t n1_idx,
    const int *restrict n2, const size_t n2_len, const size_t n2_idx,
    int *restrict memo
) {
    if (n1_idx == n1_len || n2_idx == n2_len) {
        return 0;
    }
    const size_t memo_idx = n1_idx * n2_len + n2_idx;
    if (memo[memo_idx] != -1) {
        return memo[memo_idx];
    }

    int res = 0;
    if (n1[n1_idx] == n2[n2_idx]) {
        res = 1 + dfs(n1, n1_len, n1_idx + 1, n2, n2_len, n2_idx + 1, memo);
    }
    res = MAX(res, dfs(n1, n1_len, n1_idx + 1, n2, n2_len, n2_idx, memo));
    res = MAX(res, dfs(n1, n1_len, n1_idx, n2, n2_len, n2_idx + 1, memo));

    memo[memo_idx] = res;
    return res;
}

int maxUncrossedLines(
    const int *restrict n1, const int len1,
    const int *restrict n2, const int len2
) {
    if (len1 < 1 || len1 > 500 || len2 < 1 || len2 > 500 || n1 == NULL || n2 == NULL) { return -1; }

    const size_t memo_len = (size_t)(len1 * len2);
    int *restrict memo = malloc(memo_len * sizeof(*memo));
    if (memo == NULL) { return -1; }
    for (size_t i = 0; i < memo_len; i += 1) { memo[i] = -1; }

    const int res = dfs(n1, (size_t)len1, 0, n2, (size_t)len2, 0, memo);

    free(memo);
    return res;
}
