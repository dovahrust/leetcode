int minRotations(const int n, const char *restrict s) {
    const int last = s[n - 1] - '0';
    int prev = 0;
    int res = 0;
    int max_save = 0;

    for (int i = 0; i < n; i += 1) {
        const int curr = s[i] - '0';
        const int diff = ABS(prev - curr);
        const int min_r = MIN(diff, 10 - diff);
        res += min_r;
        const int diff_last = ABS(prev - last);
        const int min_r_last = MIN(diff_last, 10 - diff_last);
        max_save = MAX(max_save, min_r - min_r_last);
        prev = curr;
    }

    return res - max_save;
}
