int findPoisonedDuration(const int *restrict time_series, const int len, const int duration) {
    if (len <= 0 || time_series == NULL) { return 0; }

    int curr = 0;
    int res = 0;
    for (int i = 0; i < len; i += 1) {
        const int t = time_series[i];
        curr = MAX(curr, t);
        res += t + duration - curr;
        curr = t + duration;
    }

    return res;
}
