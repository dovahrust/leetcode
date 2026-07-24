static inline int max_int(const int a, const int b)
{
    return a > b ? a : b;
}

static int dfs(int** grid, const int rows, const int cols, const int i, const int j)
{
    if (i < 0 || j < 0 || i >= rows || j >= cols || grid[i][j] == 0) {
        return 0;
    }

    const int val = grid[i][j];
    int res = 0;

    grid[i][j] = 0;
    res = max_int(res, val + dfs(grid, rows, cols, i - 1, j));
    res = max_int(res, val + dfs(grid, rows, cols, i + 1, j));
    res = max_int(res, val + dfs(grid, rows, cols, i, j - 1));
    res = max_int(res, val + dfs(grid, rows, cols, i, j + 1));
    grid[i][j] = val;

    return res;
}

int getMaximumGold(int** grid, const int rows, const int* cols_data)
{
    assert(rows > 0 && cols_data != NULL && cols_data[0] > 0 && grid != NULL);
    const int cols = cols_data[0];
    assert(rows <= 15 && cols <= 15);

    int res = 0;

    for (int i = 0; i < rows; i += 1) {
        for (int j = 0; j < cols; j += 1) {
            res = max_int(res, dfs(grid, rows, cols, i, j));
        }
    }

    return res;
}
