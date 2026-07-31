/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* xorQueries(
    const int* arr,
    const int arr_len,
    int** queries,
    const int queries_len,
    const int* queries_cols_data,
    int* return_len
) {
    if (arr_len <= 0 || arr == NULL || queries == NULL || queries_len <= 0 || queries_cols_data == NULL || return_len == NULL) {
        fprintf(stderr, "invalid input");
        exit(1);
    }
    int* prefix = malloc(((size_t)arr_len + 1) * sizeof(*prefix));
    int* res = malloc((size_t)queries_len * sizeof(*res));
    if (res == NULL || prefix == NULL) {
        fprintf(stderr, "alloc fail");
        exit(1);
    }
    prefix[0] = 0;
    *return_len = queries_len;

    for (int i = 0; i < arr_len; i += 1) {
        prefix[i + 1] = prefix[i] ^ arr[i];
    }

    for (int i = 0; i < queries_len; i += 1) {
        if (queries_cols_data[i] != 2) {
            fprintf(stderr, "invalid input");
            exit(1);
        }
        const int lo = queries[i][0];
        const int hi = queries[i][1];
        assert(lo >= 0 && hi >= lo && hi < arr_len);
        if (lo < 0 || lo > hi || hi >= arr_len) {
            fprintf(stderr, "invalid input");
            exit(1);
        }
        res[i] = prefix[hi + 1] ^ prefix[lo];
    }

/* cleanup: */
    free(prefix);
    return res;
}
