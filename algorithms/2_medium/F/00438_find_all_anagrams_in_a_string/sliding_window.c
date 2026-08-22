/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findAnagrams(const char *restrict s, const char *restrict p, int *restrict return_len) {
    assert(return_len != NULL);
    if (s == NULL || p == NULL || s[0] == '\0' || p[0] == '\0') {
        *return_len = -1;
        return NULL;
    }

    const size_t s_len = strlen(s);
    const size_t p_len = strlen(p);
     if (p_len > s_len) {
        *return_len = 0;
        return NULL;
    }

    size_t freqs_p[256] = { 0 };
    for (size_t i = 0; i < p_len; i += 1) {
        freqs_p[(unsigned char)p[i]] += 1;
    }

    size_t freqs_window[256] = { 0 };
    int *restrict res = NULL;
    size_t res_len = 0;
    size_t res_cap = 0;
    size_t lo = 0;

    for (size_t hi = 0; hi < s_len; hi += 1) {
        const size_t idx_bytes_hi = (size_t)(unsigned char)s[hi];
        freqs_window[idx_bytes_hi] += 1;

        while (freqs_window[idx_bytes_hi] > freqs_p[idx_bytes_hi]) {
            freqs_window[(unsigned char)s[lo]] -= 1;
            lo += 1;
        }

        if (hi - lo + 1 == p_len) {
            if (res_len == res_cap) {
                const size_t new_cap = res_cap == 0 ? 4 : res_cap * 2;
                int *ptr = realloc(res, new_cap * sizeof(*res));
                if (ptr == NULL) {
                    *return_len = -1;
                    free(res);
                    return NULL;
                }
                res = ptr;
                res_cap = new_cap;
            }
            res[res_len] = (int)lo;
            res_len += 1;
        }
    }

    assert(res_len <= INT_MAX);
    *return_len = (int)res_len;
    return res;
}
