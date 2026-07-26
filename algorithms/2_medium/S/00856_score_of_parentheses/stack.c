static inline int max_int(const int a, const int b)
{
    return a > b ? a : b;
}

int scoreOfParentheses(const char* s)
{
    assert(s != NULL && s[0] != '\0');
    const size_t s_len = strlen(s);
    const size_t stack_cap = s_len / 2;
    int* stack = malloc(stack_cap * sizeof(stack));
    assert(stack != NULL);
    size_t stack_len = 0;
    int score = 0;

    for (size_t i = 0; i < s_len; i += 1) {
        const char ch = s[i];

        if (ch == '(') {
            assert(stack_len < stack_cap && "invalid input");
            stack[stack_len] = 0;
            stack_len += 1;
        } else if (ch == ')') {
            assert(stack_len > 0 && "invalid input");
            const int curr = max_int(stack[stack_len - 1], 1);
            stack_len -= 1;
            if (stack_len == 0) {
                score += curr;
            } else {
                stack[stack_len - 1] += curr * 2;
            }
        } else {
            assert(false && "invalid input");
        }
    }

/* cleanup: */
    free(stack);
    return score;
}
