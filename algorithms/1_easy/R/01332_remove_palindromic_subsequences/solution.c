static inline bool is_pal(const char *restrict s) {
    const size_t len = strlen(s);
    ptrdiff_t hi = (ptrdiff_t)len - 1;
    ptrdiff_t lo = 0;
    while (lo < hi) {
        if (s[hi] == s[lo]) {
            lo += 1;
            hi -= 1;
        } else {
            return false;
        }
    }
    return true;
}

int removePalindromeSub(const char *restrict s) {
    if (s == NULL || s[0] == '\0') {
        return -1;
    }
    if (is_pal(s)) {
        return 1;
    }
    return 2;
}
