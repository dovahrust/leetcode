typedef ptrdiff_t isize;

inline static isize calc_range(const isize *restrict freqs, const size_t lo, const size_t hi) {
    const size_t half = ((hi - lo + 1) >> 1);
    isize res = 0;

    for (size_t i = 0; i < half; i += 1) {
        const size_t c = lo + i;
        const size_t m = hi - i;
        res += ABS(freqs[c] - freqs[m]);
    }

    return res;
}

int mirrorFrequency(const char *restrict s) {
    isize freqs[256] = { 0 };
    for (size_t i = 0; s[i] != '\0'; i += 1) {
        freqs[(unsigned char)s[i]] += 1;
    }

    const isize res = calc_range(freqs, (size_t)'a', (size_t)'z') + 
                      calc_range(freqs, (size_t)'0', (size_t)'9');

    return (int)res;
}
