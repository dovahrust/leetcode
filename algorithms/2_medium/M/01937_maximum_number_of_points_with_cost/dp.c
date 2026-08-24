long long maxPoints(int *restrict *restrict points, const int rows, const int *restrict cols_data) {
    if (rows <= 0 || points == NULL || cols_data == NULL || cols_data[0] <= 0) { return -1; }

    const int cols = cols_data[0];
    int64_t *buff = calloc(2 * (size_t)cols, sizeof(*buff));
    if (buff == NULL) { return -1; }
    int64_t *restrict curr = &buff[0];
    int64_t *restrict prev = &buff[cols];

    for (int i = 0; i < rows; i += 1) {
        int64_t curr_max = 0;
        for (int j = 0; j < cols; j += 1) {
            assert(points[i][j] >= 0 && points[i][j] <= 100000);
            curr_max -= 1;
            curr_max = MAX(curr_max, prev[j]);
            curr[j] = curr_max + points[i][j];
        }

        curr_max = 0;
        for (int j = cols - 1; j >= 0; j -= 1) {
            curr_max -= 1;
            curr_max = MAX(curr_max, prev[j]);
            curr[j] = MAX(curr[j], curr_max + points[i][j]);
        }

        void *temp = prev;
        prev = curr;
        curr = temp;
    }

    int64_t res = 0;
    for (int j = 0; j < cols; j += 1) {
        res = MAX(res, prev[j]);
    }

    free(buff);
    return res;
}
