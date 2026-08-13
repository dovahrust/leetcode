struct pair {
    int x;
    int y;
};

int removeStones(int** stones, const int len, const int *restrict cols_data) {
    if (len <= 0 || stones == NULL || cols_data == NULL) {
        goto invalid_input;
    }
    struct pair *restrict stack = malloc((size_t)len * sizeof(*stack));
    size_t stack_len = 0;
    if (stack == NULL) {
        goto alloc_fail;
    }
    bool *restrict seen = calloc((size_t)len, sizeof(*seen));
    if (seen == NULL) {
        goto alloc_fail_clean_stack;
    }
    int res = 0;

    for (int i = 0; i < len; i += 1) {
        if (!seen[i]) {
            seen[i] = true;
            int cnt = 1;
            stack[stack_len] = (struct pair){ .x = stones[i][0], .y = stones[i][1] };
            stack_len += 1;

            while (stack_len > 0) {
                stack_len -= 1;
                const int x = stack[stack_len].x;
                const int y = stack[stack_len].y;
                for (int j = 0; j < len; j += 1) {
                    if (!seen[j] && (stones[j][0] == x || stones[j][1] == y))  {
                        seen[j] = true;
                        stack[stack_len] = (struct pair){ .x = stones[j][0], .y = stones[j][1] };
                        stack_len += 1;
                        cnt += 1;
                    }
                }
            }

            res += cnt - 1;
        }
    }

    free(stack);
    free(seen);
    return res;

alloc_fail_clean_stack:
    free(stack);
alloc_fail:
invalid_input:
    return -1;
}
