static int find_parent(int *restrict parents, int u) {
    while (parents[u] != u) {
        parents[u] = parents[parents[u]];
        u = parents[u];
    }
    return u;
}

static bool merge(int *restrict parents, const int u, const int v) {
    if (v == - 1) { return true; }

    if (u == v) { return false; }

    const int pu = find_parent(parents, u);
    const int pv = find_parent(parents, v);

    if (pv != v) { return false; }

    if (pv == pu) { return false; }

    parents[v] = pu;
    return true;
}

bool validateBinaryTreeNodes(
    const int n,
    int *left_child, int left_child_len,
    int *right_child, int right_child_len
) {
    int *restrict parents = malloc((size_t)n * sizeof(*parents));
    assert(parents != NULL);
    for (int u = 0; u < n; u += 1) { parents[u] = u; }

    for (int u = 0; u < n; u += 1) {
        if (!merge(parents, u, left_child[u])) { goto false_variant; }

        if (!merge(parents, u, right_child[u])) { goto false_variant; }
    }

    const int root = find_parent(parents, 0);

    for (int u = 0; u < n; u += 1) {
        if (find_parent(parents, u) != root) { goto false_variant; }
    }

    free(parents);
    return true;

false_variant:
    free(parents);
    return false;
}
