int minimumOperations(int *restrict *restrict grid, const int rows, const int *restrict cols_data) {
    if (rows <= 1 || grid == NULL || cols_data == NULL) { return 0; }

    const int cols = cols_data[0];
    int sum = 0;

    for (int j = 0; j < cols; j += 1) {
        int prev = grid[0][j];
        for (int i = 1; i < rows; i+= 1) {
            const int target = prev + 1;
            sum += MAX(0, target - grid[i][j]);
            prev = MAX(target, grid[i][j]);
        }
    }

    return sum;
}
