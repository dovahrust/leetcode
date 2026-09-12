int longestCycle(const int *restrict edges, const int n) {
    int *restrict buff = calloc((size_t)(2 * n), sizeof(*buff));
    if (buff == NULL) { return -2; }
    int *restrict stack = &buff[0];
    int stak_len = 0;
    int *restrict deg = &buff[n];

    bool *restrict seen = calloc((size_t)n, sizeof(*seen));
    if (seen == NULL) {
        free(buff);
        return -2;
    }

    for (int u = 0; u < n; u += 1) {
        const int v = edges[u];
        if (v != -1) {
            deg[v] += 1;
        }
    }

    for (int u = 0; u < n; u += 1) {
        if (deg[u] == 0) {
            stack[stak_len] = u;
            stak_len += 1;
        }
    }

    while (stak_len > 0) {
        stak_len -= 1;
        const int u = stack[stak_len];
        seen[u] = true;
        const int v = edges[u];
        if (v != -1) {
            deg[v] -= 1;
            if (deg[v] == 0) {
                stack[stak_len] = v;
                stak_len += 1;
            }
        }
    }

    int res = -1;

    for (int i = 0; i < n; i += 1) {
        if (!seen[i]) {
            int curr = 0;
            stack[stak_len] = i;
            stak_len += 1;
            while (stak_len > 0) {
                stak_len -= 1;
                const int u = stack[stak_len];
                seen[u] = true;
                curr += 1;
                const int v = edges[u];
                if (v != -1 && !seen[v]) {
                    seen[v] = true;
                    stack[stak_len] = v;
                    stak_len += 1;
                }
            }
            res = MAX(res, curr);
        }
    }

    free(buff);
    free(seen);
    return res;
}
