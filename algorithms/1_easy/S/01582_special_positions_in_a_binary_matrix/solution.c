int numSpecial(int **mat, const int rows, const int *cols_data) {
    const int cols = cols_data[0];
    int *buff = calloc((size_t)(rows + cols), sizeof(*buff));
    if (buff == NULL) { return -1; }
    int *restrict rows_sum = &buff[0];
    int *restrict cols_sum = &buff[rows];

    for (int i = 0; i < rows; i+= 1) {
        for (int j = 0; j < cols; j += 1) {
            rows_sum[i] += mat[i][j];
            cols_sum[j] += mat[i][j];
        }
    }

    int cnt = 0;
    for (int i = 0; i < rows; i+= 1) {
        for (int j = 0; j < cols; j += 1) {
            if (mat[i][j] == 1 && rows_sum[i] == 1 && cols_sum[j] == 1) {
                cnt += 1;
            }
        }
    }

    free(buff);
    return cnt;
}
