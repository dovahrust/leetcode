#define MOD 1000000007

struct pair {
    int by_skip;
    int by_add;
};

static int dfs(
    const int n,
    const int k,
    const bool can_add_to_prev,
    struct pair *restrict memo, const size_t memo_cols
) {
    if (n <= k) { return 0; }

    if (k == 0) { return can_add_to_prev ? n : 0; }

    if (n == k + 1) { return 1; }

    const size_t memo_idx = (size_t)n * memo_cols + (size_t)k;
    const int cache = can_add_to_prev ? memo[memo_idx].by_add : memo[memo_idx].by_skip;
    if (cache != -1) {
        return cache;
    }

    int res = 0;

    const int skip = dfs(n - 1, k, false, memo, memo_cols);
    res = (res + skip) % MOD;
    if (can_add_to_prev) {
        const int keep = dfs(n - 1, k, true, memo, memo_cols);
        res = (res + keep) % MOD;
    }
    const int new_st = dfs(n - 1, k - 1, true, memo, memo_cols);
    res = (res + new_st) % MOD;

    if (can_add_to_prev) {
        memo[memo_idx].by_add = res;
    } else {
        memo[memo_idx].by_skip = res;
    }

    return res;
}

int numberOfSets(const int n, const int k) {
    const size_t memo_rows = (size_t)(n + 1);
    const size_t memo_cols = (size_t)(k + 1);
    const size_t memo_size = memo_rows * memo_cols;
    struct pair *restrict memo = malloc(memo_size * sizeof(*memo));
    if (memo == NULL) { return -1; }

    for (size_t i = 0; i < memo_size; i += 1) {
        memo[i].by_add = -1;
        memo[i].by_skip = -1;
    }

    const int res = dfs(n, k, false, memo, memo_cols);
    free(memo);
    return res;
}
