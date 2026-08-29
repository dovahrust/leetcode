typedef ptrdiff_t isize;

int countSubstrings(const char *s, const char *t) {
    if (s == NULL || t == NULL) { return -1; }
    const isize s_len = (isize)strlen(s);
    const isize t_len = (isize)strlen(t);
    isize cnt = 0;

    for (isize s_idx = 0; s_idx < s_len; s_idx += 1) {
        for (isize t_idx = 0; t_idx < t_len; t_idx += 1) {
            if (s[s_idx] != t[t_idx]) {
                isize lo = 1;
                while (s_idx - lo >= 0 && t_idx - lo >= 0 && s[s_idx - lo] == t[t_idx - lo]) {
                    lo += 1;
                }

                isize hi = 1;
                while (s_idx + hi < s_len && t_idx + hi < t_len && s[s_idx + hi] == t[t_idx + hi]) {
                    hi += 1;
                }

                cnt += hi * lo;
            }
        }
    }

    if (cnt > INT_MAX) { return -1; }

    return (int)cnt;
}
