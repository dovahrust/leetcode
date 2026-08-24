bool canConstruct(const char *restrict s, const int k_int) {
    assert(k_int >= 1 && s != NULL);
    const size_t k = (size_t)k_int;
    const size_t len = strlen(s);

    if (k > len) { return false; }

    size_t freqs[256] = { 0 };

    for (size_t i = 0; i < len; i += 1) {
        freqs[(unsigned char)s[i]] += 1;
    }

    size_t cnt_odd = 0;
    for (size_t i = 0; i < 256; i += 1) {
        if ((freqs[i] & 1) == 1) {
            cnt_odd += 1;
        }
    }

    return cnt_odd <= k;
}
