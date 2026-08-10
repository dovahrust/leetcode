__attribute__((no_sanitize("all")))
static bool dfs(
    const uint32_t curr,
    const uint32_t seen,
    const uint32_t max_valid,
    const uint32_t target,
    int8_t *restrict memo
) {
    if (memo[seen] != -1) {
        return memo[seen] == 0 ? false : true;
    }

    bool res = false;
    for (uint32_t i = 1; i <= max_valid; i += 1) {
        const uint32_t mask = (1u << (i - 1));
        if ((seen & mask) == 0) {
            if (curr + i >= target) {
                res = true;
                break;
            } else {
                res = !dfs(curr + i, seen | mask, max_valid, target, memo);
                if (res == true) {
                    break;
                }
            }
        }
    }

    memo[seen] = (res ? 1 : 0);
    return res;
}

__attribute__((no_sanitize("all")))
bool canIWin(const int max_valid, const int target) {
    if (max_valid < 1 || max_valid > 20 || target < 0 || target > 300) {
        fprintf(stderr, "invalid input");
        exit(1);
    }

    if (max_valid >= target) {
        return true;
    }

    const int sum = max_valid * (max_valid + 1) / 2;
    if (sum < target) {
        return false;
    }

    const uint32_t memo_len = (1u << (uint32_t)max_valid);
    int8_t *restrict memo = calloc((size_t)memo_len, sizeof(*memo));
    if (memo == NULL) {
        fprintf(stderr, "alloc fail");
        exit(1);
    }
    #pragma GCC unroll 8
    for (uint32_t i = 0; i < memo_len; i += 1) { memo[i] = -1; }

    const bool res = dfs(0, 0, (uint32_t)max_valid, (uint32_t)target, memo);

/* cleanup: */
    free(memo);
    return res;
}
