#define FREQS_LEN 256ULL

static inline int min_int(const int a, const int b) {
    return a < b ? a : b;
}

int longestPalindrome(const char* s) {
    if (s == NULL) { return 0; }
    const size_t len = strlen(s);
    if (len > 2000) {
        fprintf(stderr, "invalid input: len should be less than 2_000");
        exit(1);
    }

    int16_t freqs[FREQS_LEN] = { 0 };

    for (const char* it = s; *it != '\0'; it += 1) {
        freqs[(unsigned char)(*it)] += 1;
    }

    int cnt = 0;

    for (size_t i = 0; i < FREQS_LEN; i += 1) {
        cnt += freqs[i] - (freqs[i] & 1);
    }

    return min_int(cnt + 1, (int)len);
}
