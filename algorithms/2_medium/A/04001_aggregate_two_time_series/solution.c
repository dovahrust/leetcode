static inline int min_int(const int a, const int b)
{
    return a < b ? a : b;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** aggregateTimeSeries(int** series1, const int len1, const int* cols1_data,
                          int** series2, const int len2, const int* cols2_data,
                          int* return_len, int** return_cols_data)
{
    assert(len1 >= 0 && len2 >= 0);
    int** res = malloc(((size_t)len1 + (size_t)len2) * sizeof(*res));
    assert(res != NULL);
    size_t res_len = 0;
    int i1 = 0;
    int i2 = 0;

    while (i1 < len1 && i2 < len2) {
        const int time_min = min_int(series1[i1][0], series2[i2][0]);
        const int val = series1[i1][1] + series2[i2][1];
        int* temp = malloc(2 * sizeof(*temp));
        temp[0] = time_min;
        temp[1] = val;
        assert(temp != NULL);
        res[res_len] = temp;
        res_len += 1;

        if (series1[i1][0] == time_min) {
            i1 += 1;
        }

        if (series2[i2][0] == time_min) {
            i2 += 1;
        }
    }

    while (i1 < len1)  {
        int* temp = malloc(2 * sizeof(*temp));
        assert(temp != NULL);
        temp[0] = series1[i1][0];
        temp[1] = series1[i1][1];
        res[res_len] = temp;
        res_len += 1;
        i1 += 1;
    }

    while (i2 < len2)  {
        int* temp = malloc(2 * sizeof(*temp));
        assert(temp != NULL);
        temp[0] = series2[i2][0];
        temp[1] = series2[i2][1];
        res[res_len] = temp;
        res_len += 1;
        i2 += 1;
    }

    assert(res_len <= (size_t)INT_MAX);
    *return_len = (int)res_len;
    int* return_cols_data_temp = malloc(res_len * sizeof(*return_cols_data_temp));
    assert(return_cols_data_temp != NULL);
    for (size_t i = 0; i < res_len; i += 1) {
        return_cols_data_temp[i] = 2;
    }
    *return_cols_data = return_cols_data_temp;

    return res;
}
