static inline size_t min_size(const size_t a, const size_t b) {
    return a < b ? a : b;
}

__attribute__((no_sanitize("all")))
int minFlipsMonoIncr(const char *restrict s) {
    if (s == NULL) {
        goto invalid_input;
    }
    const size_t len = strlen(s);
    size_t make_ones = 0;
    for (size_t i = 0; i < len; i += 1) {
        if (s[i] == '0') {
            make_ones += 1;
        }
    }
    size_t make_zeros = 0;
    size_t res = make_ones;

    for (size_t i = 0; i < len; i += 1) {
        if (s[i] == '0') {
            make_ones -= 1;
        } else if (s[i] == '1') {
            make_zeros += 1;
        } else {
            goto invalid_input;
        }

        res = min_size(res, make_ones + make_zeros);
    }

    if (res > (size_t)INT_MAX) {
        goto invalid_input;
    }

    return (int)res;

invalid_input:
    return -1;
}
