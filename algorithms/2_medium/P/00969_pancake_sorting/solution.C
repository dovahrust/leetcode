static inline void rev(int *lo, int *hi) {
    while (lo < hi) {
        const int temp = *lo;
        *lo = *hi;
        *hi = temp;
        lo += 1;
        hi -= 1;
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* pancakeSort(int *restrict arr, const int len, int *restrict return_len) {
    if (return_len == NULL) { return NULL; }
    if (arr == NULL || len <= 0) {
        *return_len = 0;
        return NULL;
    }

    int *restrict res = NULL;
    size_t res_len = 0;
    size_t res_cap = 0;

    for (int i = len - 1; i >= 0; i -= 1) {
        int idx_max = 0;
        for (int j = 0; j <= i; j += 1) {
            if (arr[j] >= arr[idx_max]) {
                idx_max = j;
            }
        }

        if (idx_max != i) {
            if (res_len + 2 > res_cap) {
                const size_t new_cap = res_cap == 0 ? 4 : 2 * res_cap;
                int *temp = realloc(res, new_cap * sizeof(*res));
                if (temp == NULL) { goto err_free_res; }
                res_cap = new_cap;
                res = temp;
            }

            res[res_len] = idx_max + 1;
            res_len += 1;
            rev(arr, arr + idx_max);

            res[res_len] = i + 1;
            res_len += 1;
            rev(arr, arr + i);
        }
    }

    if (res_len > (size_t)INT_MAX) { goto err_free_res; }

    *return_len = (int)res_len;
    return res;

err_free_res:
    free(res);
    *return_len = -1;
    return NULL;
}
