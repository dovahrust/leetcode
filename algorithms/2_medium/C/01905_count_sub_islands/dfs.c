static bool dfs_is_sub(
    int *restrict *restrict g1,
    int *restrict *restrict g2,
    const int rows, const int cols,
    const int i, const int j,
    bool *restrict seen
) {
    if (i < 0 || j < 0 || i >= rows || j >= cols) {
        return true;
    }
    if (seen[i * cols + j] || g2[i][j] == 0) {
        return true;
    }

    bool res = true;
    seen[i * cols + j] = true;

    if (g1[i][j] == 0) {
        res = false;
    }

    res &= dfs_is_sub(g1, g2, rows, cols, i + 1, j, seen);
    res &= dfs_is_sub(g1, g2, rows, cols, i - 1, j, seen);
    res &= dfs_is_sub(g1, g2, rows, cols, i, j + 1, seen);
    res &= dfs_is_sub(g1, g2, rows, cols, i, j - 1, seen);

    return res;
}

int countSubIslands(
    int *restrict *restrict grid1, const int rows1, const int *restrict cols_data1,
    int *restrict *restrict grid2, const int rows2, const int *restrict cols_data2
) {
    if (rows1 <= 0 || rows1 != rows2 || rows1 > 500 || cols_data1 == NULL || cols_data2 == NULL ||
        cols_data1[0] <= 0 || cols_data1[0] != cols_data2[0] || cols_data1[0] > 500 ||
        grid1 == NULL || grid2 == NULL
    ) {
        return -1;
    }

    const int rows = rows1;
    const int cols = cols_data1[0];
    bool *restrict seen = calloc((size_t)(rows * cols), sizeof(*seen));
    int cnt = 0;

    for (int i = 0; i < rows; i += 1) {
        for (int j = 0; j < cols; j += 1) {
            if (!seen[i * cols + j] && grid2[i][j] == 1) {
                if (dfs_is_sub(grid1, grid2, rows, cols, i, j, seen)) {
                    cnt += 1;
                }
            }
        }
    }

    free(seen);
    return cnt;
}
