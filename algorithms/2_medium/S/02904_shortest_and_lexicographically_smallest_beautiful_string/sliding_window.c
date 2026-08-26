struct state {
    size_t lo;
    size_t hi;
    bool is_valid;
};

static char *string_from(const char *restrict s, const size_t lo, const size_t hi) {
    const size_t len = hi - lo + 2;
    char *res = malloc(len * sizeof(*res));
    if (res == NULL) {
        exit(0);
    }
    for (size_t i = lo; i <= hi; i += 1) {
        res[i - lo] = s[i];
    }
    res[hi - lo + 1] = '\0';
    return res;
}

static bool is_less_with_eq_len(const char *restrict s, size_t lo1, size_t lo2, const size_t len) {
    for (size_t i = 0; i < len; i += 1) {
        if (s[lo1 + i] < s[lo2 + i]) {
            return true;
        } else if (s[lo1 + i] > s[lo2 + i]) {
            return false;
        }
    }
    return false;
}

char* shortestBeautifulSubstring(const char *restrict s, const int k_int) {
    if (k_int < 1 || s == NULL || s[0] == '\0') { return strdup(""); }

    const size_t k = (size_t)k_int;
    const size_t len = strlen(s);
    size_t lo = 0;
    struct state res = { .lo = 0, .hi = 0, .is_valid = false };
    size_t ones = 0;

    for (size_t hi = 0; hi < len; hi += 1) {
        if (s[hi] == '1') {
            ones += 1;
        }

        while (lo <= hi && (ones > k || s[lo] == '0')) {
            if (s[lo] == '1') {
                ones -= 1;
            }
            lo += 1;
        }

        if (ones == k) {
            if (hi - lo + 1 == k) {
                return string_from(s, lo, hi);
            }

            if (!res.is_valid) {
                res.lo = lo;
                res.hi = hi;
                res.is_valid = true;
            } else {
                const size_t res_width = res.hi - res.lo + 1;
                const size_t curr_width = hi - lo + 1;

                if (curr_width < res_width) {
                    res.lo = lo;
                    res.hi = hi;
                } else if (curr_width == res_width && is_less_with_eq_len(s, lo, res.lo, curr_width)) {
                    res.lo = lo;
                    res.hi = hi;
                }
            }

            lo += 1;
            ones -= 1;
        }
    }

    if (!res.is_valid) {
        return strdup("");
    }

    return string_from(s, res.lo, res.hi);
}
