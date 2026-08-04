static inline int min_int(const int a, const int b) {
    return a < b ? a : b;
}

static inline int max_int(const int a, const int b) {
    return a > b ? a : b;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findMissingElements(const int* nums, const int len, int* return_len) {
    if (nums == NULL || len <= 0) {
        fprintf(stderr, "invalid input");
        goto err;
    }

    int max = INT_MIN;
    int min = INT_MAX;

    for (int i = 0; i < len; i += 1) {
        min = min_int(min, nums[i]);
        max = max_int(max, nums[i]);
    }

    const size_t seen_len = (size_t)((int64_t)max - (int64_t)min + 1);
    bool* seen = calloc(seen_len, sizeof(*seen));

    if (seen == NULL) {
        fprintf(stderr, "alloc fail");
        goto err;
    }

    size_t res_len = seen_len;
    for (int i = 0; i < len; i += 1) {
        const size_t seen_idx = (size_t)((int64_t)nums[i] - min);
        if (!seen[seen_idx]) {
            res_len -= 1;
            seen[seen_idx] = true;
        }
    }

    int* res = NULL;

    if (res_len > INT_MAX) {
        fprintf(stderr, "int limit err");
        goto cleanup_err;
    }

    *return_len = (int)res_len;
    if (res_len == 0) {
        goto cleanup;
    }

    res = malloc(res_len * sizeof(*res));
    if (res == NULL) {
        fprintf(stderr, "alloc fail");
        goto cleanup_err;
    }

    size_t res_idx = 0;
    for (size_t i = 0; i < seen_len; i += 1) {
        if (!seen[i]) {
            res[res_idx] = (int)((int64_t)i + min);
            res_idx += 1;
        }
    }

cleanup:
    free(seen);
    return res;

cleanup_err:
    free(seen);
err:
    *return_len = -1;
    return NULL;
}
