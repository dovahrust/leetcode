static int max_int(const int a, const int b) {
    return a > b ? a : b;
}

bool find132pattern(const int* nums, const int len) {
    assert(len > 0 && nums != NULL);
    int* stack = malloc((size_t)len * sizeof(*stack));
    assert(stack != NULL);
    int stack_len = 0;
    int third = INT_MIN;
    bool res = false;

    for (int i = len - 1; i >= 0; i -= 1) {
        const int num = nums[i];
        if (num < third) {
            res = true;
            goto cleanup;
        }

        while (stack_len > 0 && num > stack[stack_len - 1]) {
            third = max_int(third, stack[stack_len - 1]);
            stack_len -= 1;
        }

        stack[stack_len] = num;
        stack_len += 1;
    }

cleanup:
    free(stack);
    return res;
}
