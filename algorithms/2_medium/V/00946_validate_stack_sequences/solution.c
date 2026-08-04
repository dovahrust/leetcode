bool validateStackSequences(
    const int* pushed, const int pushed_len,
    const int* popped, const int popped_len
) {
    if (pushed_len != popped_len || pushed_len <= 0 || pushed == NULL || popped == NULL) {
        fprintf(stderr, "invalid input");
        exit(1);
    }

    const int len = pushed_len;
    int* stack = malloc((size_t)len * sizeof(*stack));
    if (stack == NULL) {
        fprintf(stderr, "alloc fail");
        exit(1);
    }
    int stack_len = 0;
    int popped_index = 0;
    bool res = false;

    for (int i = 0; i < len; i += 1) {
        stack[stack_len] = pushed[i];
        stack_len += 1;

        while (stack_len > 0 && stack[stack_len - 1] == popped[popped_index]) {
            stack_len -= 1;
            popped_index += 1;

            if (popped_index == popped_len) {
                res = true;
                goto cleanup;
            }
        }
    }

cleanup:
    free(stack);
    return res;
}
