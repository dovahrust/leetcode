static inline int max_int(const int a, const int b)
{
    return a > b ? a : b;
}

static int dfs(int** grid, const int rows, const int cols, const int i, const int j, int* memo)
{
    if (j + 1 == cols) {
        return 0;
    }

    const size_t memo_idx = (size_t)i * (size_t)cols + (size_t)j;
    if (memo[memo_idx] != -1) {
        return memo[memo_idx];
    }

    int max = 0;
    const int curr_val = grid[i][j];

    if (i > 0 && grid[i - 1][j + 1] > curr_val) {
        max = max_int(max, 1 + dfs(grid, rows, cols, i - 1, j + 1, memo));
    }

    if (grid[i][j + 1] > curr_val) {
        max = max_int(max, 1 + dfs(grid, rows, cols, i, j + 1, memo));
    }

    if (i + 1 < rows && grid[i + 1][j + 1] > curr_val) {
        max = max_int(max, 1 + dfs(grid, rows, cols, i + 1, j + 1, memo));
    }

    memo[memo_idx] = max;
    return max;
}

int maxMoves(int** grid, const int rows, const int* cols_data)
{
    assert(rows > 0 && cols_data != NULL && cols_data[0] > 0 && grid != NULL);
    const int cols = cols_data[0];
    const size_t memo_len = (size_t)rows * (size_t)cols;
    int* memo = malloc(memo_len * sizeof(*memo));
    assert(memo != NULL);
    for (size_t i = 0; i < memo_len; i += 1) { memo[i] = -1; }
    int max = 0;

    for (int i = 0; i < rows; i += 1) {
        max = max_int(max, dfs(grid, rows, cols, i, 0, memo));
    }

/* cleanup: */
    free(memo);
    return max;
}
