#define NONE INT64_MAX

static int64_t dfs(const int *nums, const int len, const int idx, int64_t *memo) {
    if (len == idx) { return 0; }

    if (idx + 1 == len) { return (int64_t)nums[idx]; }

    if (memo[idx] != NONE) { return memo[idx]; }

    const int64_t sum1 = (int64_t)nums[idx];
    const int64_t sum2 = (int64_t)nums[idx] + (int64_t)nums[idx + 1];
    const int64_t score1 = sum1 % 3 == 0 ? (sum1 - dfs(nums, len, idx + 1, memo)) : (sum1 + dfs(nums, len, idx + 1, memo));
    const int64_t score2 = sum2 % 3 == 0 ? (sum2 - dfs(nums, len, idx + 2, memo)) : (sum2 + dfs(nums, len, idx + 2, memo));

    const int64_t res = MAX(score1, score2);
    memo[idx] = res;

    return res;
}

long long maxDifference(const int *nums, const int len) {
    int64_t *memo = malloc((size_t)len * sizeof(*memo));
    if (memo == NULL) { exit(1); };
    for (int i = 0; i < len; i += 1) { memo[i] = NONE; }

    const int64_t res = dfs(nums, len, 0, memo);

    free(memo);
    return res;
}
