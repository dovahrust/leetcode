struct pair {
    int buy;
    int sell;
};

static inline int max_int(const int a, const int b) {
    return a > b ? a : b;
}

static int dfs(
    const int *restrict prices, const int len,
    const int idx,
    const bool buy,
    struct pair *restrict memo
) {
    if (len <= idx) {
        return 0;
    }

    const int memo_val = buy ? memo[idx].buy : memo[idx].sell;
    if (memo_val != - 1) {
        return memo_val;
    }

    int res = 0;
    if (buy) {
        res = max_int(res, dfs(prices, len, idx + 1, false, memo) - prices[idx]);
        res = max_int(res, dfs(prices, len, idx + 1, true, memo));
    } else {
        res = max_int(res, dfs(prices, len, idx + 2, true, memo) + prices[idx]);
        res = max_int(res, dfs(prices, len, idx + 1, false, memo));
    }

    if (buy) {
        memo[idx].buy = res;
    } else {
        memo[idx].sell = res;
    }

    return res;
}

int maxProfit(const int *restrict prices, const int len) {
    if (len < 1 || len > 5000 || prices == NULL) {
        fprintf(stderr, "invalid input");
        exit(1);
    }

    struct pair *restrict memo = malloc((size_t)len * sizeof(*memo));
    if (memo == NULL) {
        fprintf(stderr, "alloc fail");
        exit(1);
    }
    for (int i = 0; i < len; i += 1) {
        memo[i].buy = -1;
        memo[i].sell = -1;
    }

    const int res = dfs(prices, len, 0, true, memo);

/* cleanup: */
    free(memo);
    return res;
}
