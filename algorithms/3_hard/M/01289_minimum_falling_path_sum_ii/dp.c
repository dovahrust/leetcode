struct tuple {
    int min1;
    int min2;
    int min1_idx;
};

inline static struct tuple calc_min1_min2(const int *restrict arr, const int len) {
    int min1 = INT_MAX;
    int min2 = INT_MAX;
    int min1_idx = 0;

    for (int i = 0; i < len; i += 1) {
        const int v = arr[i];
        if (v <= min1) {
            min2 = min1;
            min1_idx = i;
            min1 = v;
        } else if (v <= min2) {
            min2 = v;
        }
    }

    return (struct tuple){ .min1 = min1, .min2 = min2, .min1_idx = min1_idx };
}

int minFallingPathSum(int *restrict *restrict grid, const int rows, const int *restrict cols_data) {
    assert(rows > 0 && rows == cols_data[0]);

    const int n = rows;
    if (n == 1) { return grid[0][0]; }

    int *restrict buff = calloc((size_t)n * 2, sizeof(*buff));
    assert(buff != NULL);
    int *restrict curr = &buff[0];
    int *restrict prev = &buff[n];

    for (int i = n - 1; i >= 0; i -= 1) {
        const int *restrict g = grid[i];
        const struct tuple data_mins = calc_min1_min2(prev, n);
        for (int j = 0; j < n; j += 1) {
            curr[j] = g[j] + data_mins.min1;
        }
        curr[data_mins.min1_idx] = g[data_mins.min1_idx] + data_mins.min2;

        void *tmp = curr;
        curr = prev;
        prev = tmp;
    }

    int min = INT_MAX;
    for (int i = 0; i < n; i += 1) {
        min = MIN(min, prev[i]);
    }

    free(buff);
    return min;
}
