#define INF SIZE_MAX

enum state {
    NOT_SEEN,
    ONCE_SEEN,
    MULTI_SEEN,
};

int firstUniqChar(const char *restrict s) {
    enum state states[256] = { 0 };
    size_t first_seen[256] = { 0 };

    for (size_t i = 0; s[i] != '\0'; i += 1) {
        const unsigned char ch = (unsigned char)s[i];

        if (states[ch] == NOT_SEEN) {
            states[ch] = ONCE_SEEN;
            first_seen[ch] = i;
        } else {
            states[ch] = MULTI_SEEN;
        }
    }

    size_t res = INF;

    for (size_t i = 0; i < 256; i += 1) {
        if (states[i] == ONCE_SEEN) {
            res = MIN(res, first_seen[i]);
        }
    }

    if (res == INF) {
        return -1;
    }

    return (int)res;
}
