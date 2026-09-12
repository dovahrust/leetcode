struct pair {
    int node;
    int next;
};

struct pair_int_int {
    int f;
    int s;
};

int numOfMinutes(
    const int n, const int head_id,
    const int *manager, const int manager_len,
    const int *inform_time, const int inform_time_len
) {
    struct pair *restrict adj = malloc((size_t)(2 * n - 1) * sizeof(*adj));
    int adj_len = n;
    if (adj == NULL) { return -1; }
    for (int i = 0; i < n; i += 1){
        adj[i] = (struct pair){ .node = -1, .next = -1 };
    }
    for (int i = 0; i < n; i += 1){
        const int m = manager[i];
        if (m != -1) {
            const int next = adj[m].next;
            adj[m].next = adj_len;
            adj[adj_len] = (struct pair){ .node = i, .next = next };
            adj_len += 1;
        }
    }
    struct pair_int_int *restrict stack = malloc((size_t)n * sizeof(*stack));
    if (stack == NULL) {
        free(adj);
        return -1;
    }
    int stack_len = 1;
    stack[0] = (struct pair_int_int){ .f = 0, .s = head_id };
    int res = 0;

    while (stack_len > 0) {
        stack_len -= 1;
        const int u = stack[stack_len].s;
        const int cost = stack[stack_len].f;
        res = MAX(res, cost);

        const int new_cost = cost + inform_time[u];
        int curr = adj[u].next;
        while (curr != -1) {
            stack[stack_len] = (struct pair_int_int){ .f = new_cost, .s = adj[curr].node };
            stack_len += 1;
            curr = adj[curr].next;
        }
    }

    free(adj);
    free(stack);
    return res;
}
