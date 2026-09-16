static int cmp(const void *a_ptr, const void *b_ptr) {
    const int a = *(const int*)a_ptr;
    const int b = *(const int*)b_ptr;

    return (a > b) - (a < b);
}

long long maximumImportance(int n, int** roads, int roads_rows, int* roads_cols_data) {
    int *restrict deg = calloc((size_t)n, sizeof(*deg));
    if (deg == NULL) { return -1; }

    for (int i = 0; i < roads_rows; i += 1) {
        const int u = roads[i][0];
        const int v = roads[i][1];
        deg[u] += 1;
        deg[v] += 1;
    }

    qsort(deg, (size_t)n, sizeof(*deg), cmp);

    int64_t res = 0;
    for (int i = 0; i < n; i += 1) {
        const int64_t imp = i + 1;
        const int64_t d = deg[i];
        res += d * imp;
    }

    free(deg);
    return res;
}
