inline static bool is_pal(const char *restrict s, size_t begin, size_t end) {
    while (begin < end) {
        end -= 1;

        if (s[begin] != s[end]) {
            return false;
        }

        begin += 1;
    }

    return true;
}      

int maxPalindromes(const char *restrict s, const int k_int) {
    const size_t k = (size_t)k_int;
    const size_t len = strlen(s);

    if (k > len) { return 0; }

    if (k == 1) { return (int)len; }

    size_t i = 0;
    size_t cnt = 0;

    int cntt = 0;

    while (i + k <= len) {
        if (is_pal(s, i, i + k)) {
            i += k;
            cnt += 1;
        } else if (i + k + 1 <= len && is_pal(s, i, i + k + 1)) {
            i += k + 1;
            cnt += 1;
        } else {
            i += 1;
        }
    }

    return (int)cnt;
}
