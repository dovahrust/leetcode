struct pair {
    int val;
    int64_t cnt;
};

 __attribute__((no_sanitize("all")))
long long shadowPairs(const int *restrict nums, const int len) {
    struct pair *restrict stack = malloc((size_t)len * sizeof(*stack));
    int stack_len = 0;
    int64_t cnt = 0;

    for (int i = 0; i < len; i += 1) {
        const int num = nums[i];

        while (stack_len > 0 && stack[stack_len - 1].val > num) {
            stack_len -= 1;
        }

        if (stack_len > 0) {
            const int top = stack[stack_len - 1].val;
            const int64_t prev_num_cnt = stack[stack_len - 1].cnt;

            if (top == num) {
                cnt += prev_num_cnt;
                stack[stack_len] = (struct pair){ .val = top, .cnt = prev_num_cnt};
                stack_len += 1;
            } else {
                cnt += stack_len;
                stack[stack_len] = (struct pair){ .val = num, .cnt = stack_len};
                stack_len += 1;
            }
        } else {
            stack[0] = (struct pair){ .val = num, .cnt = 0};
            stack_len = 1;
        }
    }

    free(stack);
    return cnt;
}
