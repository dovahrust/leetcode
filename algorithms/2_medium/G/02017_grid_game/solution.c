long long gridGame(int *restrict *restrict grid, const int rows, const int *restrict cols_data) {
    if (rows != 2 || grid == NULL || cols_data == NULL) { return - 1; }

    const int cols = cols_data[0];
    if (cols <= 1) { return 0; }

    int64_t u = 0;
    for (int j = 1; j < cols; j += 1) {
        u += grid[0][j];
    }
    int64_t d = 0;
    int64_t res = u;

    for (int j = 1; j < cols; j += 1) {
        u -= grid[0][j];
        d += grid[1][j - 1];
        res = MIN(res, MAX(u, d));
    }

    return res;
}
