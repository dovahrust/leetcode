typedef ptrdiff_t isize;

#define LAND 0
#define WATER 1
#define LAND_VISITED -1

static void dfs(
    int **grid,
    const int rows,
    const int cols,
    const int i,
    const int j
) {
    if (i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] != LAND) { return; }

    grid[i][j] = LAND_VISITED;

    dfs(grid, rows, cols, i + 1, j);
    dfs(grid, rows, cols, i - 1, j);
    dfs(grid, rows, cols, i, j + 1);
    dfs(grid, rows, cols, i, j - 1);
}

int closedIsland(int **grid, const int rows, const int *cols_data) {
    const int cols = cols_data[0];
    int cnt = 0;

    for (int i = 0; i < rows; i += 1) {
        dfs(grid, rows, cols, i, 0);
        dfs(grid, rows, cols, i, cols - 1);
    }

    for (int j = 0; j < cols; j += 1) {
        dfs(grid, rows, cols, 0, j);
        dfs(grid, rows, cols, rows - 1, j);
    }

    for (int i = 0; i < rows; i += 1) {
        for (int j = 0; j < cols; j += 1) {
            if (grid[i][j] == LAND) {
                cnt += 1;
                dfs(grid, rows, cols, i, j);
            }
        }
    }

    return cnt;
}
