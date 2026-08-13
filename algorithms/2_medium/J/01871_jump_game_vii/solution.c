static inline ptrdiff_t min_isize(const ptrdiff_t a, const ptrdiff_t b) {
    return a < b ? a : b;
}

bool canReach(const char* s, const int min_jump, const int max_jump) {
    if (min_jump < 1 || min_jump > max_jump || s == NULL) { goto invalid_input; }
    const ptrdiff_t len = (ptrdiff_t)strlen(s);
    if (len < 2 || len > 100000) { goto invalid_input; }

    if (s[len - 1] != '0' || s[0] != '0') { return false; }

    int* diff = calloc((size_t)(len + 1), sizeof(*diff));
    if (diff == NULL) { goto alloc_fail; }
    diff[0] = 1;
    diff[1] = -1;

    int balance = 0;
    for (ptrdiff_t i = 0; i < len; i += 1) {
        balance += diff[i];
        if (balance > 0) {
            if (i == len - 1) {
                return true;
            }

            if (s[i] != '0') {
                continue;
            }

            const ptrdiff_t begin = min_isize(i + min_jump, len);
            const ptrdiff_t end = min_isize(i + max_jump + 1, len);

            diff[begin] += 1;
            diff[end] -= 1;
        }
    }

    free(diff);
    return false;

alloc_fail:
    fprintf(stderr, "alloc fail\n");
    exit(1);

invalid_input:
    fprintf(stderr, "invalid input\n");
    exit(1);
}
