/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* stableMountains(const int *restrict height, const int len, int threshold, int *restrict return_len) {
    if (return_len == NULL) { return NULL; }
    if (height == NULL || len <= 1) {
        *return_len = 0;
        return NULL;
    }

    int *restrict res = NULL;
    size_t res_len = 0;
    size_t res_cap = 0;

    for (int i = 1; i < len; i += 1) {
        if (height[i - 1] > threshold) {
            if (res_cap == res_len) {
                const size_t new_cap = MIN((size_t)len, (res_cap == 0 ? 4 : res_cap * 2));
                void *ptr = realloc(res, new_cap * sizeof(*res));
                if (ptr == NULL) {
                    *return_len = -1;
                    free(res);
                    return NULL;
                }
                res = ptr;
                res_cap = new_cap;
            }
            res[res_len] = i;
            res_len += 1;
        }
    }

    *return_len = (int)res_len;
    return res;
}
