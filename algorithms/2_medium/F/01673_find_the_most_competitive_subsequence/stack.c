/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* mostCompetitive(const int *restrict nums, const int len, const int k, int *restrict return_len) {
    if (return_len == NULL) { goto invalid_input; }
    if (k < 1 || k > len || nums == NULL) { goto invalid_input_set_len; }

    int *restrict stack = malloc((size_t)k * sizeof(*stack));
    if (stack == NULL) { goto alloc_fail; }
    int stack_len = 0;

    for (int i = 0; i < len; i += 1) {
        const int num = nums[i];
        const int remains = len - i;

        while (stack_len > 0 && remains + stack_len > k && stack[stack_len - 1] > num) {
            stack_len -= 1;
        }

        if (stack_len < k) {
            stack[stack_len] = num;
            stack_len += 1;
        }
    }

    *return_len = k;
    return stack;

alloc_fail:
invalid_input_set_len:
    *return_len = -1;
invalid_input:
    return NULL;
}
