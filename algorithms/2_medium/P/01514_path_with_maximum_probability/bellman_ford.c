double maxProbability(
    const int n,
    int **edges, const int edges_len, int *edges_cols_data,
    const double *succ_prob, const int succ_prob_len,
    const int st,
    const int ed
) {
    double *prob = calloc((size_t)n, sizeof(*prob));
    if (prob == NULL) { return -1.0; }
    prob[st] = 1.0;

    for (int steps = 0; steps < n; steps += 1) {
        bool has_update = false;

        for (int i = 0; i < edges_len; i += 1) {
            const int u = edges[i][0];
            const int v = edges[i][1];
            const double w = succ_prob[i];

            if (w * prob[u] > prob[v]) {
                prob[v] = w * prob[u];
                has_update = true;
            }

            if (w * prob[v] > prob[u]) {
                prob[u] = w * prob[v];
                has_update = true;
            }
        }

        if (!has_update) { break; }
    }

    const double res = prob[ed];
    free(prob);
    return res;
}
