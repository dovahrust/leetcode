int maxRepeating(const char *sequence, const char *word) {
    if (sequence == NULL || word == NULL || sequence[0] == '\0' || word[0] == '\0') { return 0; }

    const size_t s_len = strlen(sequence);
    const size_t w_len = strlen(word);

    if (w_len > s_len) { return 0; }

    size_t *restrict dp = calloc(s_len - w_len + 2, sizeof(*dp));

    for (size_t i = 0; i <= s_len - w_len; i += 1) {
        bool eq = true;
        for (size_t j = 0; j < w_len; j += 1) {
            if (sequence[i + j] != word[j]) {
                eq = false;
                break;
            }
        }
        if (eq) {
            dp[i] = 1 + (i >= w_len ? dp[i - w_len] : 0);
        }
    }

    size_t max = 0;
    for (size_t i = 0; i < s_len - w_len + 2; i += 1) {
        max = MAX(max, dp[i]);
    }
    free(dp);

    if (max > (size_t)INT_MAX) { return -1; }

    return (int)max;
}
