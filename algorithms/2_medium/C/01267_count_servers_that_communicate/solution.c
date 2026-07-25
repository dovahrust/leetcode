
__attribute__((no_sanitize("all")))
int countServers(int** grid, const int rows, const int* cols_data)
{
    assert(rows >= 1 && rows <= 250 && cols_data != NULL);
    const int cols = cols_data[0];
    assert(cols >= 1 && cols <= 250);

    int* buff = calloc((size_t)(rows + cols), sizeof(*buff));
    assert(buff != NULL);
    int* sum_rows = &buff[0];
    int* sum_cols = &buff[rows];
    int total = 0;

    for (int i = 0; i < rows; i += 1) {
        for (int j = 0; j < cols; j += 1) {
            if (grid[i][j] == 1) {
                total += 1;
                sum_rows[i] += 1;
                sum_cols[j] += 1;
            }
        }
    }

    for (int i = 0; i < rows; i += 1) {
        for (int j = 0; j < cols; j += 1) {
            if (grid[i][j] == 1 && sum_rows[i] == 1 && sum_cols[j] == 1) {
                total -= 1;
            }
        }
    }

/* cleanup: */
    free(buff);
    return total;
}
