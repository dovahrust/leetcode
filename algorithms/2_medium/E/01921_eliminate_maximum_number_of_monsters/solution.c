static int cmp(const void *a_ptr, const void *b_ptr) {
    const int a = *(int*)a_ptr;
    const int b = *(int*)b_ptr;
    return (a > b) - (a < b);
}

int eliminateMaximum(
    const int *restrict dist, const int dist_len,
    const int *restrict speed, const int speed_len
) {
    if (speed_len <= 0 || dist_len != speed_len || dist == NULL || speed == NULL) {
        return -1;
    }

    const int len = dist_len;

    int *restrict arr = malloc((size_t)len * sizeof(*arr));
    if (arr == NULL) { return -1; }
    int arr_len = 0;

    for (int i = 0; i < len; i += 1) {
        if (speed[i] <= 0 || dist[i] <= 0) {
            return -1;
        }

        arr[arr_len] = (dist[i] + speed[i] - 1) / speed[i];
        arr_len += 1;
    }
    qsort(arr, (size_t)len, sizeof(*arr), cmp);

    for (int i = 0; i < len; i += 1) {
        if (arr[i] < i + 1) {
            return i;
        }
    }

    return len;
}
