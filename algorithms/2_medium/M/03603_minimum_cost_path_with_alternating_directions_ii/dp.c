static inline int64_t min_int64(const int64_t a, const int64_t b) {
    return a < b ? a : b;
}

__attribute__((no_sanitize("all")))
long long minCost(
    int rows,
    int cols,
    int** wait_costs,
    const int wait_costs_rows,
    const int* wait_costs_cols_data
) {
    if (rows <= 0 || cols <= 0 || 100000 / cols < rows || wait_costs == NULL) {
        fprintf(stderr, "invalid input");
        exit(1);
    }

    int64_t* buff = malloc((2 * (size_t)cols) * sizeof(*buff));
    if (buff == NULL) {
        fprintf(stderr, "invalid input");
        exit(1);
    }
    int64_t *restrict prev = &buff[0];
    int64_t *restrict curr = &buff[cols];
    prev[0] = 0;
    #pragma GCC unroll 8
    for (int j = 1; j < cols; j += 1) { prev[j] = INT64_MAX; }

    for (int i = 0; i < rows; i += 1) {
        #pragma GCC unroll 4
        for (int j = 0; j < cols; j += 1) {
            const int64_t entry_cost = (int64_t)(i + 1) * (j + 1);
            const int wait_cost = ((i == 0 && j == 0) || (i == rows - 1 && j == cols - 1)) ? 0 : wait_costs[i][j];
            const int64_t up = prev[j];
            const int64_t left = j == 0 ? INT64_MAX : curr[j - 1];
            curr[j] = min_int64(up, left) + entry_cost + wait_cost;
        }
        int64_t *restrict temp = prev;
        prev = curr;
        curr = temp;
    }

    const int64_t res = prev[cols - 1];

/* cleanup: */
    free(buff);
    return res;
}
