#define INF INT_MAX

int minSumOfLengths(const int *restrict arr, const int len, int target) {
    assert(target > 0);
    if (len <= 1) { return -1; }

    int *restrict dp = malloc((size_t)(len + 1) * sizeof(*dp));
    if (dp == NULL) { return -2; }
    for (int i = 0; i <= len; i += 1) { dp[i] = INF; }
    int res = INF;
    int lo = 0;
    int curr_sum = 0;
    for (int hi = 0; hi < len; hi += 1) {
        curr_sum += arr[hi];
        while (curr_sum > target) {
            curr_sum -= arr[lo];
            lo += 1;
        }

        if (curr_sum == target) {
            const int w = hi + 1 - lo;
            dp[hi + 1] = MIN(w, dp[hi]);

            if (dp[lo] != INF) {
                res = MIN(res, w + dp[lo]);
            }
        } else {
            dp[hi + 1] = dp[hi];
        }
    }

    free(dp);

    if (res == INF) {
        return -1;
    }

    return res;
}

