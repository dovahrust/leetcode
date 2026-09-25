char* getSmallestString(int n, int k) {
    char *restrict res = malloc(((size_t)n + 1)  * sizeof(*res));
    if (res == NULL) { return NULL; }

    res[n] = '\0';

    for (int i = 0; i < n; i += 1) {
        res[i] = 'a';
    }

    k -= n;
    for (int i = n - 1; i >= 0; i -= 1) {
        if (k <= 25) {
            res[i] += k;
            break;
        } else {
            res[i] += 25;
            k -= 25;
        }
    }

    return res;
}
