int getMaximumGenerated(int n) {
    if (n == 0) { return 0; }

    int *restrict arr = calloc((size_t)(n + 1), sizeof(*arr));
    if (arr == NULL) { return -1; }
    arr[1] = 1;
    int max = 1;
    for (int i = 2; i <= n; i += 1) {
        if ((i & 1) == 1) {
            arr[i] = arr[i / 2] + arr[(i / 2) + 1];
        } else {
            arr[i] = arr[i / 2];
        }

        max = MAX(max, arr[i]);
    }

    free(arr);
    return max;
}
