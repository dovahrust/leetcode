__attribute__((no_sanitize("all")))
static inline size_t max_size(const size_t a, const size_t b) {
    return a > b ? a : b;
}

__attribute__((no_sanitize("all")))
int lengthLongestPath(const char *restrict input) {
    if (input == NULL) {
        fprintf(stderr, "invalid input");
        exit(1);
    }

    const size_t input_len = strlen(input);
    size_t* stack = NULL;
    size_t stack_cap = 0;
    size_t stack_len = 0;
    size_t max_len = 0;
    size_t last_len = 0;
    bool is_file = false;
    size_t stack_sum = 0;
    size_t input_idx = 0;

    while (input_idx < input_len) {
        if (input[input_idx] == '\n') {
            if (stack_cap == stack_len) {
                stack_cap = stack_cap == 0 ? 4 : 2 * stack_cap;
                size_t* temp = realloc(stack, stack_cap * sizeof(*stack));
                if (temp == NULL) {
                    free(stack);
                    fprintf(stderr, "alloc fail");
                    exit(1);
                }
                stack = temp;
            }
            stack[stack_len] = last_len;
            stack_len += 1;
            stack_sum += last_len;
            last_len = 0;
            size_t cnt_bt = 0;
            while (input_idx + 1 < input_len && input[input_idx + 1] == '\t') {
                cnt_bt += 1;
                input_idx += 1;
            }
            while (cnt_bt < stack_len) {
                stack_sum -= stack[stack_len - 1];
                stack_len -= 1;
                is_file = false;
            }
        } else {
            last_len += 1;
            if (input[input_idx] == '.') {
                is_file = true;
            }

            if (is_file) {
                max_len = max_size(max_len, last_len + stack_sum + stack_len);
            }
        }

        input_idx += 1;
    }

    if (max_len > (size_t)INT_MAX) {
        fprintf(stderr, "cast fail");
        exit(1);
    }

/* cleanup: */
    free(stack);
    return (int)max_len;
}
