static inline int min_int(const int a, const int b) {
    return a < b ? a : b;
}

static int dfs(const int x, const int y, int* memo) {
    if (x <= y) {
        return y - x;
    }

    if (memo[x] != -1) {
        return memo[x];
    }

    int res = x - y;
    if (x % 5 == 0) {
        res = min_int(res, 1 + dfs(x / 5, y, memo));
    } else {
        const int diff = x % 5;
        res = min_int(res, 1 + diff + dfs(x / 5, y, memo));
        res = min_int(res, 1 + 5 - diff + dfs(1 + (x / 5), y, memo));
    }

    if (x % 11 == 0) {
        res = min_int(res, 1 + dfs(x / 11, y, memo));
    } else {
        const int diff = x % 11;
        res = min_int(res, 1 + diff + dfs(x / 11, y, memo));
        res = min_int(res, 1 + 11 - diff + dfs(1 + (x / 11), y, memo));
    }

    memo[x] = res;
    return res;
}

int minimumOperationsToMakeEqual(int x, int y) {
    if (x > 10000 && x < 1 && y < 1 && y > 10000) {
        fprintf(stderr, "invalid input");
        exit(1);
    }

    if (x <= y) {
        return y - x;
    }

    int* memo = malloc((size_t)(x + 1) * sizeof(*memo));
    if (memo == NULL) {
        fprintf(stderr, "alloc fail");
        exit(1);
    }
    for (int i = 0; i <= x; i += 1) { memo[i] = -1; }

    const int res = dfs(x, y, memo);
/* cleanup: */
    free(memo);
    return res;
}
