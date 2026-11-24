long long numOfSubsequences(const char *restrict s) {
    if (s == NULL) { return 0; }

    const size_t len = strlen(s);
    int64_t t = 0;
    for (size_t i = 0; i < len; i += 1) { t += (int)(s[i] == 'T'); }

    int64_t l = 0;
    int64_t ct = 0;
    int64_t lc = 0;
    int64_t max_t_times_l = 0;
    int64_t res = 0;

    for (size_t i = 0; i < len; i += 1) {
        switch (s[i]) {
            case 'T':
                t -= 1;
                break;
            case 'L':
                l += 1;
                max_t_times_l = MAX(max_t_times_l, l * t);
                break;
            case 'C':
                ct += t;
                lc += l;
                res += l * t;
            default:
                break;
        }
    }

    return res + MAX(max_t_times_l, MAX(lc, ct));
}
