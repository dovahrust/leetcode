#define RESET_COST 1

int minDays(int n) {
    assert(n >= 1 && n <= 100000);
    int width = 1;
    int width_cost = 1;
    int *restrict dp = malloc((size_t)(n + 1) * sizeof(*dp));
    if (dp == NULL) { return -1; }
    dp[0] = 0;
    for (int i = 1; i <= n; i += 1) { dp[i] = INT_MAX; }

    while (width <= n) {
        dp[width] = width_cost;

        for (int i = width + 1; i <= n; i += 1) {
            dp[i] = MIN(dp[i], dp[i - width] + width_cost + RESET_COST);
        }

        width_cost += 1;
        width += width_cost;
    }

    const int res = dp[n];
    free(dp);
    return res;
}
