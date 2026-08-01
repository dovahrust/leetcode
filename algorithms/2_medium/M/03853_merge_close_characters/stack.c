typedef ptrdiff_t isize;

char* mergeCharacters(const char* s, const int k_int) {
    if (s == NULL) { return NULL; }
    const isize len = (isize)strlen(s);
    const isize k = k_int;
    isize prev_idx[256];
    for (isize i = 0; i < 256; i += 1) { prev_idx[i] = -1; }
    char* stack = malloc((size_t)(len + 1) * sizeof(*stack));
    isize stack_len = 0;

    for (isize i = 0; i < len; i += 1) {
        const unsigned char ch = (unsigned char)s[i];
        if (prev_idx[ch] == -1 || stack_len - prev_idx[ch] > k) {
            prev_idx[ch] = stack_len;
            stack[stack_len] = ch;
            stack_len += 1;
        }
    }

    stack[stack_len] = '\0';
    return stack;
}
