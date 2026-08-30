struct vec_vec {
    int *restrict *restrict ptr;
    int *restrict cols_data;
    size_t len;
    size_t cap;
    bool err;
};

struct vec {
    int *restrict ptr;
    size_t len;
    size_t cap;
    bool err;
};

static void dfs(
    const int *restrict candidates,
    const int len,
    const int idx,
    const int target,
    struct vec_vec *restrict res,
    struct vec *restrict tmp
) {
    if (res->err || tmp->err) { return; }

    if (target == 0) {
        if (tmp->len > (size_t)INT_MAX) {
            tmp->err = true;
            return;
        }

        if (res->cap == res->len) {
            const size_t new_cap = res->cap == 0 ? 4 : 2 * res->cap;
            void *ptr = realloc(res->ptr, new_cap * sizeof(*(res->ptr)));
            if (ptr == NULL) {
                res->err =true;
                return;
            }
            res->ptr = ptr;

            void *ptr2 = realloc(res->cols_data, new_cap * sizeof(*(res->cols_data)));
            if (ptr2 == NULL) {
                res->err =true;
                return;
            }
            res->cols_data = ptr2;
            res->cap = new_cap;
        }
        int *restrict tmp_dup = malloc(tmp->len * sizeof(*tmp_dup));
        if (tmp_dup == NULL) {
            tmp->err = true;
            return;
        }
        for (size_t i = 0; i < tmp->len; i += 1) {
            tmp_dup[i] = tmp->ptr[i];
        }
        res->ptr[res->len] = tmp_dup;
        res->cols_data[res->len] = (int)tmp->len;
        res->len += 1;
        return;
    }


    if (target < 0 || idx >= len) {
        return;
    }

    if (tmp->cap == tmp->len) {
        const size_t new_cap = tmp->cap == 0 ? 4 : 2 * tmp->cap;
        void *ptr = realloc(tmp->ptr, new_cap * sizeof(*(tmp->ptr)));
        if (ptr == NULL) {
            tmp->err =true;
            return;
        }
        tmp->ptr = ptr;
        tmp->cap = new_cap;
    }

    tmp->ptr[tmp->len] = candidates[idx];
    tmp->len += 1;
    dfs(candidates, len, idx, target - candidates[idx], res, tmp);
    tmp->len -= 1;

    dfs(candidates, len, idx + 1, target, res, tmp);
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combinationSum(
    const int *restrict candidates, const int len,
    const int target,
    int *restrict return_len, int **return_cols_data
) {
    if (return_len == NULL) { return NULL; }
    if (return_cols_data == NULL || len <= 0 || candidates == NULL || target <= 0) { goto err; }

    struct vec_vec res = { .ptr = NULL, .len = 0, .cap = 0, .cols_data = NULL, .err = false };
    struct vec tmp = { .ptr = NULL, .len = 0, .cap = 0, .err = false };

    dfs(candidates, len, 0, target, &res, &tmp);

    if (res.err || tmp.err || res.len > (size_t)INT_MAX) { goto cleanup_err; }

    *return_len = (int)res.len;
    *return_cols_data = res.cols_data;
    free(tmp.ptr);

    return res.ptr;

cleanup_err:
    for (size_t i = 0; i < res.len; i += 1) {
        free(res.ptr[i]);
    }
    free(res.ptr);
    free(tmp.ptr);
    free(res.cols_data);
err:
    *return_len = -1;
    return NULL;
}
