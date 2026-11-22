int minChanges(const char *restrict s) {
    const size_t len = strlen(s);
    int cnt = 0;

    for (size_t i = 1; i < len; i += 2) {
        if (s[i] != s[i - 1]) {
            cnt += 1;
        }
    }

    return cnt;
}
