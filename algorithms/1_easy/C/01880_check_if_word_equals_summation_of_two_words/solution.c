static uint32_t calc_val(const char *restrict s) {
    assert(s != NULL);
    uint32_t res = 0;
    const size_t len = strlen(s);
    assert(len <= 8 && len >= 1);
    for (size_t i = 0; i < len; i += 1) {
        assert(s[i] >= 'a' && s[i] <= 'j');
        res = res * 10 + (uint32_t)(s[i] - 'a');
    }
    return res;
}

bool isSumEqual(const char *first_word, const char *second_word, const char *target_word) {
    const uint32_t f = calc_val(first_word);
    const uint32_t s = calc_val(second_word);
    const uint32_t t = calc_val(target_word);

    return f + s == t;
}
