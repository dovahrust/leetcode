static inline size_t max_size(const size_t a, const size_t b) {
    return a > b ? a : b;
}

int maximumLengthSubstring(char* s) {
    if (s == NULL) { return 0; }
    const size_t len = strlen(s);
    int8_t freqs[256] = { 0 };
    size_t lo = 0;
    size_t max = 0;

    for (size_t hi = 0; s[hi] != '\0'; hi += 1) {
        freqs[(unsigned char)s[hi]] += 1;

        while (freqs[(unsigned char)s[hi]] > 2) {
            freqs[(unsigned char)s[lo]] -= 1;
            lo += 1;
        }

        max = max_size(max, hi + 1 - lo);
    }

    if (max > (size_t)INT_MAX) { return -1; }

    return (int)max;
}
