inline static void reverse(int *restrict begin, int *restrict end) {
    while (begin < end) {
        end -= 1;
        const int temp = *begin;
        *begin = *end;
        *end = temp;
        begin += 1;
    }
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** rotateGrid(
    int *restrict *restrict grid, const int rows, const int *restrict cols_data,
    const int k,
    int *restrict return_len, int *restrict *restrict return_cols_data
){
    if (rows <= 0 || (rows & 1) != 0 || rows > 50 ||
        cols_data == NULL || cols_data[0] <= 0 || cols_data[0] > 50 || (cols_data[0] & 1) != 0 ||
        grid == NULL || return_cols_data == NULL || return_len == NULL
    ) {
        goto invalid_input;
    }
    const int cols = cols_data[0];;
    int *restrict buff = malloc(2u * (size_t)(rows + cols) * sizeof(*buff));
    if (buff == NULL) {
        goto alloc_fail;
    }
    int *restrict *restrict res = malloc((size_t)rows * sizeof(*res));
    if (res == NULL) {
        goto alloc_fail_free_buff;
    }
    int *restrict res_cols = malloc((size_t)rows * sizeof(*res_cols));
    if (res_cols == NULL) {
        goto alloc_fail_free_buff_free_res;
    }

    for (int i = 0; i < rows; i += 1) {
        res_cols[i] = cols;
        res[i] = malloc((size_t)cols * sizeof(*res[i]));
        if (res[i] == NULL) {
            for (int idx = 0; idx < i; i += 1) {
                free(res[i]);
            }
            goto alloc_fail_free_buff_free_res_free_cols;
        }
    }

    int buff_len = 0;
    int i_lo = 0;
    int i_hi = rows - 1;
    int j_lo = 0;
    int j_hi = cols - 1;

    while (i_lo < i_hi && j_lo < j_hi) {
        buff_len = 0;
        for (int i = i_lo; i <= i_hi; i += 1) {
            buff[buff_len] = grid[i][j_lo];
            buff_len += 1;
        }
        for (int j = j_lo + 1; j <= j_hi; j += 1) {
            buff[buff_len] = grid[i_hi][j];
            buff_len += 1;
        }
        for (int i = i_hi - 1; i >= i_lo; i -= 1) {
            buff[buff_len] = grid[i][j_hi];
            buff_len += 1;
        }
        for (int j = j_hi - 1; j >= j_lo + 1; j -= 1) {
            buff[buff_len] = grid[i_lo][j];
            buff_len += 1;
        }
        const int need = buff_len - k % buff_len;
        reverse(buff, buff + need);
        reverse(buff + need, buff + buff_len);
        reverse(buff, buff + buff_len);

        int idx = 0;
        for (int i = i_lo; i <= i_hi; i += 1) {
            res[i][j_lo] = buff[idx];
            idx += 1;
        }
        for (int j = j_lo + 1; j <= j_hi; j += 1) {
            res[i_hi][j] = buff[idx];
            idx += 1;
        }
        for (int i = i_hi - 1; i >= i_lo; i -= 1) {
            res[i][j_hi] = buff[idx];
            idx += 1;
        }
        for (int j = j_hi - 1; j >= j_lo + 1; j -= 1) {
            res[i_lo][j] = buff[idx];
            idx += 1;
        }
        i_lo += 1;
        i_hi -= 1;
        j_lo += 1;
        j_hi -= 1;
    }

    free(buff);
    *return_len = rows;
    *return_cols_data = res_cols;
    return res;

alloc_fail_free_buff_free_res_free_cols:
    free(res_cols);
alloc_fail_free_buff_free_res:
    free(res);
alloc_fail_free_buff:
    free(buff);
alloc_fail:
    *return_len = -1;
    return NULL;

invalid_input:
    *return_len = -1;
    return NULL;
}
