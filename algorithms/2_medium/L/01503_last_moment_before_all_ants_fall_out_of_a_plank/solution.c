int getLastMoment(const int n, const int *left, const int left_len, const int *right, const int right_len) {
    int res = 0;
    for (int i = 0; i < left_len; i += 1) {
        res = MAX(res, left[i]);
    }
    for (int i = 0; i < right_len; i += 1) {
        res = MAX(res, n - right[i]);
    }
    return res;
}
