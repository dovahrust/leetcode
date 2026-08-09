bool areAlmostEqual(const char *s1, const char *s2) {
    const size_t s1_len = strlen(s1);
    const size_t s2_len = strlen(s2);
    if (s1_len != s2_len) { return false; }

    // cnt short-circuits at >2 mismatches, so each freq is only updated for
    // at most two indices; the deltas stay within [-2, 2]. i8 is safe.
    int8_t freqs[256] = { 0 };
    int cnt = 0;

    for (size_t i = 0; i < s1_len; i += 1) {
        if (s1[i] != s2[i]) {
            cnt += 1;
            if (cnt > 2) {
                return false;
            }
            freqs[(unsigned char)s1[i]] += 1;
            freqs[(unsigned char)s2[i]] -= 1;
        }
    }

    for (size_t i = 0; i < 256; i += 1) {
        if (freqs[i] != 0) {
            return false;
        }
    }

    return true;
}
