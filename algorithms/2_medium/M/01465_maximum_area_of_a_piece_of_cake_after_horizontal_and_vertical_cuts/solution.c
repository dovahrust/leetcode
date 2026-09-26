#define MOD 1000000007

static int cmp(const void *a_ptr, const void *b_ptr) {
    const int a = *(const int*)a_ptr;
    const int b = *(const int*)b_ptr;
    return (a > b) - (a < b);
}

static int64_t calc_max(const int *restrict arr, const int len, const int end) {
    int prev = 0;
    int max = 0;
    for (int i = 0; i < len; i += 1){
        max = MAX(max, arr[i] - prev);
        prev = arr[i];
    }
    max = MAX(max, end - prev);

    return (int64_t)max;
}

int maxArea(int h, int w, int *horizontal_cuts, int horizontal_cuts_len, int *vertical_cuts, int vertical_cuts_len) {
    qsort(horizontal_cuts, (size_t)horizontal_cuts_len, sizeof(*horizontal_cuts), cmp);
    qsort(vertical_cuts, (size_t)vertical_cuts_len, sizeof(*vertical_cuts), cmp);

    const int64_t max_h = calc_max(horizontal_cuts, horizontal_cuts_len, h);
    const int64_t max_w = calc_max(vertical_cuts, vertical_cuts_len, w);

    return (int)((max_h * max_w) % MOD);
}
