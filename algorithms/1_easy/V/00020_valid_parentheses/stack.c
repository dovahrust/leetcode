bool isValid(const char *restrict s) {
    const size_t len = strlen(s);
    char *restrict stack = malloc(len * sizeof(*stack));
    if (stack == NULL) { exit(1); }
    size_t stack_len = 0;
    for (size_t i = 0; i < len; i += 1) {
        const char ch = s[i];
        switch (ch) {
            case ('}'):
            case (']'):
            case (')'):
                if (stack_len == 0) {  return false; }

                const char top_char = stack[stack_len - 1];

                if ((ch == '}' && top_char == '{')
                    || (ch == ']' && top_char == '[')
                    || (ch == ')' && top_char == '('))
                {
                    stack_len -= 1;
                } else {
                    return false;
                }
                break;
            default:
                stack[stack_len] = ch;
                stack_len += 1;
                break;
        }
    } 

    return stack_len == 0;
}
