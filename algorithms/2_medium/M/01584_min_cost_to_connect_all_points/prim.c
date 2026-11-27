int minCostConnectPoints(int **points, const int n, const int *points_cols_len) {
    bool *restrict in_tree = calloc((size_t)n, sizeof(*in_tree));
    int *restrict min_dist = malloc((size_t)n * sizeof(*min_dist));
    if (in_tree == NULL || min_dist == NULL) { goto err; }

    for (int i = 0; i < n; i += 1) { min_dist[i] = INT_MAX; }
    min_dist[0] = 0;
    int res = 0;

    for (int step = 0; step < n; step += 1) {
        int u = INT_MAX;
        int best = INT_MAX;

        for (int i = 0; i < n; i += 1) {
            if (!in_tree[i] && min_dist[i] < best) {
                best = min_dist[i];
                u = i;
            }
        }

        res += best;
        in_tree[u] = true;

        const int ux = points[u][0];
        const int uy = points[u][1];
        for (int i = 0; i < n; i += 1) {
            if (!in_tree[i]) {
                const int vx = points[i][0];
                const int vy = points[i][1];
                min_dist[i] = MIN(min_dist[i], ABS(ux - vx) + ABS(uy - vy));
            }
        }
    }

    free(in_tree);
    free(min_dist);
    return res;

err:
    free(in_tree);
    free(min_dist);
    return -1;
}
