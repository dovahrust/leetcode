int numSplits(const char *restrict s) {
    if (s == NULL || s[0] == '\0' || s[1] == '\0') { return 0; }

    const size_t len = strlen(s);
    int cnt_right = 0;
    size_t freqs_right[256] = { 0 };
    for (size_t i = 0; i < len; i += 1) {
        if (freqs_right[(unsigned char)s[i]] == 0) {
            cnt_right += 1;
        }
        freqs_right[(unsigned char)s[i]] += 1;
    }

    size_t freqs_left[256] = { 0 };
    int cnt_left = 0;

    size_t res = 0;
    for (size_t i = 0; i < len; i += 1) {
        if (cnt_left == cnt_right) {
            res += 1;
        }

        freqs_right[(unsigned char)s[i]] -= 1;
        if (freqs_right[(unsigned char)s[i]] == 0) {
            cnt_right -= 1;
        }

        if (freqs_left[(unsigned char)s[i]] == 0) {
            cnt_left += 1;
        }
        freqs_left[(unsigned char)s[i]] += 1;
    }

    if (res > (size_t)INT_MAX) { return -1; }
    return (int)res;
}
