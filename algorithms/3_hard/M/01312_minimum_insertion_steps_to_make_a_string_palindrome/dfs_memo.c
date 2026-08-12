__attribute__((no_sanitize("all")))
static inline int16_t min_i16(const int16_t a, const int16_t b) {
    return a < b ? a : b;
}

__attribute__((no_sanitize("all")))
static int16_t dfs(
    const char *restrict s, const size_t len,
    const size_t lo, const size_t hi,
    int16_t *restrict memo
) {
    if (lo >= hi) {
        return 0;
    }

    const size_t memo_idx = lo * len + hi;
    if (memo[memo_idx] != -1) {
        return memo[memo_idx];
    }

    int16_t res = INT16_MAX;

    if (s[lo] == s[hi]) {
        res = dfs(s, len, lo + 1, hi - 1, memo);
    } else {
        res = 1 + min_i16(
            dfs(s, len, lo + 1, hi, memo),
            dfs(s, len, lo, hi - 1, memo)
        );
    }

    memo[memo_idx] = res;
    return res;
}

__attribute__((no_sanitize("all")))
int minInsertions(const char *restrict s) {
    if (s == NULL) { goto invalid_input; }

    const size_t len = strlen(s);
    if (len < 1 || len > 500) { goto invalid_input; }

    const size_t memo_len = (size_t)(len * len);
    int16_t *restrict memo = malloc(memo_len * sizeof(*memo));
    if (memo == NULL) { goto alloc_fail; }
    for (size_t i = 0; i < memo_len; i += 1) { memo[i] = -1; }


    const int16_t res = dfs(s, len, 0, len - 1, memo);

    free(memo);
    return res;

alloc_fail:
invalid_input:
    return -1;
}
