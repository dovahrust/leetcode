int countGoodSubstrings(const char *restrict s) {
    if (s == NULL || s[0] == '\0' || s[1] == '\0') { return 0; }

    size_t cnt = 0;

    for (size_t i = 2; s[i] != '\0'; i += 1) {
        if (s[i] != s[i - 1] && s[i] != s[i - 2] && s[i - 1] != s[i - 2]) {
            cnt += 1;
        }
    }

    if (cnt > (size_t)INT_MAX) { return -1; }

    return(int)cnt;
}
