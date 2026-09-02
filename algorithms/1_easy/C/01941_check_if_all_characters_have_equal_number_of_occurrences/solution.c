bool areOccurrencesEqual(const char *restrict s) {
    if (s == NULL || s[0] == '\0') { return true; }
    size_t freqs[256] = { 0 };

    for (size_t i = 0; s[i] != '\0'; i += 1) {
        freqs[(unsigned char)s[i]] += 1;
    }

    const size_t freq_first = freqs[(unsigned char)s[0]];
    for (size_t i = 0; i < 256; i += 1) {
        if (freqs[i] != 0 && freqs[i] != freq_first) {
            return false;
        }
    }

    return true;
}
