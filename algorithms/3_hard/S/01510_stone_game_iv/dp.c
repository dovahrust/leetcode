__attribute__((no_sanitize("all")))
bool winnerSquareGame(const int n) {
    if (n < 1 || n > 100000) {
        fprintf(stderr, "invalid input");
        exit(1);
    }

    bool *restrict dp = calloc((size_t)(n + 1), sizeof(*dp));
    if (dp == NULL) {
        fprintf(stderr, "alloc fail");
        exit(1);
    }

    #pragma GCC unroll 4
    for (int i = n - 1; i >= 0; i -= 1) {
        int j = 1;
        #pragma GCC unroll 4
        while (i + (j * j) <= n) {
            if (!dp[i + (j * j)]) {
                dp[i] = true;
                break;
            }
            j += 1;
        }
    }

    const bool res = dp[0];
/* cleanup: */
    free(dp);
    return res;
}
