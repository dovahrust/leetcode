__attribute__((no_sanitize("all")))
static int cmp(const void *restrict a_ptr, const void *restrict b_ptr) {
    const int *const restrict a = *(const int *const restrict *const restrict)a_ptr;
    const int *const restrict b = *(const int *const restrict *const restrict)b_ptr;

    if (a[0] == b[0]) {
        return (a[1] > b[1]) - (a[1] < b[1]);
    } else {
        return (a[0] > b[0]) - (a[0] < b[0]);
    }
}

__attribute__((no_sanitize("all")))
int numberOfWeakCharacters(int *restrict *restrict properties, const int len, const int *restrict cols_data) {
    if (len < 2 || properties == NULL || cols_data == NULL || cols_data[0] != 2) { return -1; }

    qsort(properties, (size_t)len, sizeof(*properties), cmp);

    int cnt = 0;
    int curr_max = INT_MIN;
    int level = properties[len - 1][0];
    int level_max = properties[len - 1][1];

    for (int i = len - 1; i >= 0; i -= 1) {
        const int *restrict p = properties[i];
        if (p[0] < level) {
            curr_max = MAX(curr_max, level_max);
            level = p[0];
            level_max = p[1];
        }

        if (p[1] < curr_max) {
            cnt += 1;
        }
    }

    return cnt;
}
