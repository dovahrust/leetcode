#define MAX_NUM 70
#define MIN_NUM 1

__attribute__((no_sanitize("all")))
int minimizeTheDifference(
    int *restrict *restrict mat, const int rows, const int *restrict cols_data,
    const int target
) {
    if (rows <= 0 || rows > 70 || mat == NULL || cols_data == NULL || cols_data[0] <= 0 || cols_data[0] > 70) {
        goto invalid_input;
    }
    const int cols = cols_data[0];

    int max_sum = 0;
    for (int i = 0; i < rows; i += 1) {
        if (cols_data[i] != cols) { goto invalid_input; }

        const int *restrict line = mat[i];
        int max = INT_MIN;
        for (int j = 0; j < cols; j += 1) {
            const int v = line[j];
            if (v < MIN_NUM || v > MAX_NUM) {
                goto invalid_input;
            }
            max = MAX(max, v);
        }
        max_sum += max;
    }

    const int states_len = max_sum + 1;
    bool *restrict buff = calloc((size_t)(2 * states_len), sizeof(*buff));
    if (buff == NULL) { goto alloc_fail; }
    bool *restrict prev = &buff[0];
    bool *restrict curr = &buff[states_len];
    prev[0] = true;

    for (int i = 0; i < rows; i += 1) {
        const int *restrict line = mat[i];
        for (int k = 0; k < states_len; k += 1) {
            if (!prev[k]) { continue; }

            for (int j = 0; j < cols; j += 1) {
                const int v = line[j];
                curr[k + v] = true;
            }

            prev[k] = false;
        }

        bool *restrict temp = curr;
        curr = prev;
        prev = temp;
    }

    int min = INT_MAX;
    for (int i = 0; i < states_len; i += 1) {
        if (prev[i]) {
            min = MIN(min, ABS(i - target));
        }
    }

    free(buff);
    return min;

alloc_fail:
invalid_input:
    return -1;
}
