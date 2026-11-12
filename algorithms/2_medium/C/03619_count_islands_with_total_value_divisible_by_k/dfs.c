int64_t dfs(int **grid, const int i, const int j, const int rows, const int cols) {
    if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == 0) { return 0; }

    const int64_t curr = grid[i][j];
    grid[i][j] = 0;

    return curr +
           dfs(grid, i + 1, j, rows, cols) +
           dfs(grid, i - 1, j, rows, cols) +
           dfs(grid, i, j + 1, rows, cols) +
           dfs(grid, i, j - 1, rows, cols);
}


int countIslands(int **grid, int rows, int *cols_data, const int k) {
    int count = 0;
    const int cols = cols_data[0];

    for (int i = 0; i < rows; i += 1) {
        for (int j = 0; j < cols; j += 1) {
            if (grid[i][j] != 0) {
                const int64_t sum = dfs(grid, i, j, rows, cols);

                if (sum % k == 0) { count += 1; }
            }
        }
    }

    return count;
}
