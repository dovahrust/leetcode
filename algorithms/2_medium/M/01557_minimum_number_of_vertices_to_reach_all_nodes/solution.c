/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findSmallestSetOfVertices(
    const int n,
    int *restrict *restrict edges, const int len, const int *restrict cols_data,
    int *restrict return_len
) {
    assert(n >= 2 && n <= 100000 && return_len != NULL);
    bool *has_parent = calloc((size_t)n, sizeof(*has_parent));
    if (has_parent == NULL) { goto alloc_fail; }

    int res_cap = n;
    for (int i = 0; i < len; i += 1) {
        const int u = edges[i][0];
        const int v = edges[i][1];
        assert(u >= 0 && u < n && v >= 0 && v < n);
        if (!has_parent[v]) {
            has_parent[v] = true;
            res_cap -= 1;
        }
    }

    assert(res_cap > 0);
    int *res = malloc((size_t)res_cap * sizeof(*res));
    if (res == NULL) { goto alloc_fail_free_parents; }
    int res_len = 0;

    for (int i = 0; i < n; i += 1) {
        if (!has_parent[i]) {
            res[res_len] = i;
            res_len += 1;
        }
    }

    free(has_parent);
    *return_len = res_len;
    return res;

alloc_fail_free_parents:
    free(has_parent);
alloc_fail:
    *return_len = -1;
    return NULL;
}
