long long maximumSubsequenceCount(const char *restrict text, const char *pattern) {
    const char p1 = pattern[0];
    const char p2 = pattern[1];
    int64_t p1_cnt = 0;
    int64_t p2_cnt = 0;
    int64_t res = 0;

    for (size_t i = 0; text[i] != '\0'; i += 1) {
        if (text[i] == p2) {
            res += p1_cnt;
            p2_cnt += 1;
        }

        if (text[i] == p1) { p1_cnt += 1; }
    }

    return res + MAX(p1_cnt, p2_cnt);
}
