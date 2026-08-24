struct tuple {
    int sum;
    int col;
    int val;
};

static int cmp(const void *a_ptr, const void *b_ptr) {
    const struct tuple *a = a_ptr;
    const struct tuple *b = b_ptr;

    if (a->sum == b->sum) {
        return (a->col > b->col) - (a->col < b->col);
    }

    return (a->sum > b->sum) - (a->sum < b->sum);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDiagonalOrder(
    int *restrict *restrict nums, const int rows, const int *restrict cols_data,
    int *restrict return_len
) {
    if (return_len == NULL) { return NULL; }
    if (nums == NULL || rows < 0 || cols_data == NULL) { goto invalid_input; }

    int64_t total_element = 0;
    for (int i = 0; i < rows; i += 1) {
        if (cols_data[i] < 0 || (int64_t)cols_data[i] + i > 100000) { goto invalid_input; }
        total_element += cols_data[i];
    }
    if (total_element == 0) { goto return_empty_res; }
    if (total_element > 100000) { goto invalid_input;}

    struct tuple* arr = malloc((size_t)total_element * sizeof(*arr));
    int arr_len = 0;
    if (arr == NULL) { goto alloc_fail; }
    int* res = malloc((size_t)total_element * sizeof(*res));
    if (res == NULL) {
        free(arr);
        goto alloc_fail;
    }

    for (int i = 0; i < rows; i += 1) {
        const int cols = cols_data[i];
        for (int j = 0; j < cols; j += 1) {
            arr[arr_len] = (struct tuple){ .sum = i + j, .col = j, .val = nums[i][j] };
            arr_len += 1;
        }
    }

    qsort(arr, (size_t)total_element, sizeof(*arr), cmp);

    for (int64_t i = 0; i < total_element; i += 1) {
        res[i] = arr[i].val;
    }

    free(arr);
    *return_len = (int)total_element;
    return res;

return_empty_res:
    *return_len = 0;
    return NULL;

alloc_fail:
invalid_input:
    *return_len = -1;
    return NULL;
}
