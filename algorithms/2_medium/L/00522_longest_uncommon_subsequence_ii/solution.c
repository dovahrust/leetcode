typedef ptrdiff_t isize;

inline static bool is_sub(const char *a, const char *b) {
    size_t a_idx = 0;
    size_t b_idx = 0;

    while (a[a_idx] != '\0' && b[b_idx] != '\0') {
        if (a[a_idx] == b[b_idx]) {
            a_idx += 1;
        }
        b_idx += 1;
    }

    return a[a_idx] == '\0';
}

int findLUSlength(char** strs, const int len) {
    assert(len >= 2);
    isize res = -1;
    for (int i = 0; i < len; i += 1) {
        for (int j = 0; j < len; j += 1) {
            if (i == j) { continue; }

            if (is_sub(strs[i], strs[j])) {
                goto continue_main_loop;
            }
        }

        res = MAX(res, (isize)strlen(strs[i]));

        continue_main_loop:
            continue;
    }

    assert(res <= INT_MAX);
    return (int)res;
}
