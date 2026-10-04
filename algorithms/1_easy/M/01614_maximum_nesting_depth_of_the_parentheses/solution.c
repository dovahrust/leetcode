int maxDepth(const char *restrict s) {
    int max_depth = 0;
    int curr_depth = 0;

    for (size_t i = 0; s[i] != '\0'; i += 1) {
        if (s[i] == '(') {
            curr_depth += 1;
            max_depth = MAX(max_depth, curr_depth);
        } else if (s[i] == ')') {
            curr_depth -= 1;
        }
    }

    return max_depth;
}
