static int cmp(const void *a_ptr, const void *b_ptr) {
    const size_t a = *(size_t*)a_ptr;
    const size_t b = *(size_t*)b_ptr;

    if (a < b) {
        return 1;
    } else if (a == b) {
        return 0;
    } else {
        return -1;
    }
}

int minDeletions(const char *restrict s) {
    if (s == NULL || s[0] == '\0') { return 0; }

    size_t freqs[256] = { 0 };
    for (size_t i = 0; s[i] != '\0'; i += 1) {
        freqs[(unsigned char)s[i]] += 1;
    }
    qsort(freqs, 256, sizeof(size_t), cmp);
    size_t cnt = 0;
    size_t prev = freqs[0];
    for (size_t i = 1; i < 256; i += 1) {
        if (freqs[i] == 0) {
            break;
        }

        if (prev > 0) {
            prev -= 1;
        }

        if (freqs[i] > prev) {
            cnt += freqs[i] - prev;
        }

        prev = MIN(prev, freqs[i]);
    }

    if (cnt > (size_t)INT_MAX) { return -1; }

    return (int)cnt;
}
