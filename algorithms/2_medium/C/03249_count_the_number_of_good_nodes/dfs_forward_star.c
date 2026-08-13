struct pair {
    int node;
    int next;
};

__attribute__((no_sanitize("all")))
static int dfs(
    const int curr,
    const struct pair *restrict adj,
    bool *restrict visited,
    int *restrict cnt
) {
    visited[curr] = true;

    int next_child = adj[curr].next;
    int size = 1;
    int prev_child_size = -1;
    bool is_valid = true;

    while (next_child != -1) {
        const int v = adj[next_child].node;
        next_child = adj[next_child].next;

        if (visited[v]) {
            continue;
        }

        const int curr_child_size = dfs(v, adj, visited, cnt);
        if (prev_child_size == -1) {
            prev_child_size = curr_child_size;
        } else if (prev_child_size != curr_child_size) {
            is_valid = false;
        }

        size += curr_child_size;
    }

    if (is_valid) {
        *cnt += 1;
    }

    return size;
}

__attribute__((no_sanitize("all")))
int countGoodNodes(int* *restrict edges, const int edges_len, const int *restrict edges_cols_data) {
    const int n = edges_len + 1;
    if (n > 100000 || n < 2 || edges == NULL || edges_cols_data == NULL) {
        goto invalid_input;
    }
    struct pair *restrict adj = malloc((size_t)(3 * n) * sizeof(*adj));
    if (adj == NULL) {
        goto alloc_fail;
    }
    for (int i = 0; i < n; i += 1) {
        adj[i] = (struct pair){.node = -1, .next = -1};
    }
    int adj_len = n;
    for (int i = 0; i < edges_len; i += 1) {
        if (edges_cols_data[i] != 2) {
            goto invalid_input_clean_adj;
        }
        const int u = edges[i][0];
        const int v = edges[i][1];
        if (u < 0 || v < 0 || u >= n || v >= n) {
            goto invalid_input_clean_adj;
        }

        const int next_v = adj[v].next;
        adj[v].next = adj_len;
        adj[adj_len] = (struct pair){.node = u, .next = next_v};
        adj_len += 1;

        const int next_u = adj[u].next;
        adj[u].next = adj_len;
        adj[adj_len] = (struct pair){.node = v, .next = next_u};
        adj_len += 1;
    }

    int cnt = 0;
    bool *restrict visited = calloc((size_t)n, sizeof(*visited));
    if (visited == NULL) {
        goto alloc_fail_free_adj;
    }

    dfs(0, adj, visited, &cnt);

    free(adj);
    free(visited);
    return cnt;

alloc_fail_free_adj:
    free(adj);
alloc_fail:
    fprintf(stderr, "alloc fail\n");
    return -1;

invalid_input_clean_adj:
    free(adj);
invalid_input:
    fprintf(stderr, "invalid input\n");
    return -1;
}
