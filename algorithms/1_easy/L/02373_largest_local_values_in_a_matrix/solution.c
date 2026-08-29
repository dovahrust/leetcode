/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** largestLocal(
    int *restrict *restrict grid, const int rows, const int *restrict cols_data,
    int *restrict return_len, int *restrict *restrict return_cols_data
) {
    if (return_len == NULL) { goto err; }
    if (grid == NULL || rows < 3 || cols_data == NULL || cols_data[0] != rows || return_cols_data == NULL) {
        goto err_set_code;
    }

    const int n = rows;
    int *restrict *restrict res = malloc((size_t)(n - 2) * sizeof(*res));
    if (res == NULL) { goto err_set_code; }
    int *restrict res_cols_data = malloc((size_t)(n - 2) * sizeof(*res_cols_data));
    if (res_cols_data == NULL) { goto err_free_res; }

    for (int i = 0; i < n - 2; i += 1) {
        res_cols_data[i] = n - 2;
        int *restrict tmp = malloc((size_t)(n - 2) * sizeof(*tmp));
        if (tmp == NULL) {
            for (int idx = 0; idx < i; idx += 1) {
                free(res[i]);
            }
            goto err_free_res_and_cols_data;
        }

        for (int j = 0; j < n - 2; j += 1) {
            int max = INT_MIN;
            for (int ofs_i = 0; ofs_i < 3; ofs_i += 1) {
                for (int ofs_j = 0; ofs_j < 3; ofs_j += 1) {
                    max = MAX(max, grid[i + ofs_i][j + ofs_j]);
                }
            }
            tmp[j] = max;
        }

        res[i] = tmp;
    }

    *return_len = n - 2;
    *return_cols_data = res_cols_data;
    return res;

err_free_res_and_cols_data:
    free(cols_data);
err_free_res:
    free(res);
err_set_code:
    *return_len = -1;
err:
    return NULL;
}
