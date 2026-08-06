struct entity {
    int v;
    int next;
};

__attribute__((no_sanitize("all")))
static inline struct entity* init_adj(
    const int n,
    int** edges, const int rows, const int* cols_data
) {
    struct entity* ptr = malloc(((size_t)n + (size_t)rows) * sizeof(*ptr));
    if (ptr == NULL) {
        fprintf(stderr, "alloc fail");
        exit(1);
    }

    for (int i = 0; i < n; i += 1) {
        ptr[i].v = -1;
        ptr[i].next = -1;
    }

    for (int i = 0; i < rows; i += 1) {
        if (cols_data[i] != 2) {
            fprintf(stderr, "invalid input");
            exit(1);
        }
        const int u = edges[i][0];
        const int v = edges[i][1];
        if (u < 0 || v < 0 || u >= n || v >= n) {
            fprintf(stderr, "invalid input");
            exit(1);
        }

        const int next = ptr[u].next;
        ptr[n + i].v = v;
        ptr[n + i].next = next;
        ptr[u].next = n + i;
    }

    return ptr;
}

__attribute__((no_sanitize("all")))
static inline bool* init_is_sus(
    const int n, const int k,
    const struct entity *restrict adj
) { 
    int *restrict stack = malloc((size_t)n * sizeof(*stack));
    bool *restrict is_sus = calloc((size_t)n, sizeof(*is_sus));
    if (is_sus == NULL || stack == NULL) {
        fprintf(stderr, "alloc fail");
        exit(1);
    }

    stack[0] = k;
    size_t stack_len = 1;
    is_sus[k] = true;

    while (stack_len > 0) {
        stack_len -= 1;
        const int u = stack[stack_len];

        int idx = adj[u].next;
        while (idx != -1) {
            const int v = adj[idx].v;
            if (!is_sus[v])  {
                stack[stack_len] = v;
                stack_len += 1;
                is_sus[v] = true;
            }
            idx = adj[idx].next;
        }
    }

    free(stack);
    return is_sus;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
__attribute__((no_sanitize("all")))
int* remainingMethods(
    int n, int k,
    int** invocations, const int rows, const int* cols_data,
    int* return_len
) {
    if (n < 1 || n > 100000 || k < 0 || k >= n || rows > 200000 ||
        rows < 0 || (rows > 0 && (invocations == NULL || cols_data == NULL))
    ) {
        fprintf(stderr, "invalid input");
        exit(1);
    }

    const struct entity *restrict adj = init_adj(n, invocations, rows, cols_data);
    const bool *restrict is_sus = init_is_sus(n, k, adj);

    int* res = malloc((size_t)n * sizeof(*res));
    if (res == NULL) {
        fprintf(stderr, "alloc fail");
        exit(1);
    }

    for (int node = 0; node < n; node += 1) {
        if (!is_sus[node]) {
            int idx = adj[node].next;
            while (idx != -1) {
                const int v = adj[idx].v;
                if (is_sus[v]) {
                    for (int i = 0; i < n; i += 1) {
                        res[i] = i;
                    }
                    *return_len = n;

                    goto cleanup;
                }
                idx = adj[idx].next;
            }
        }
    }

    int res_len = 0;
    for (int i = 0; i < n; i += 1) {
        if (!is_sus[i]) {
            res[res_len] = i;
            res_len += 1;
        }
    }
    *return_len = res_len;

cleanup:
    free(adj);
    free(is_sus);
    return res;
}
