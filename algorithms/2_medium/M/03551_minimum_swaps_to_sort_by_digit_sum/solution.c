#define INVALID_SUM -1

struct cell {
    int sum;
    int num;
    int idx;
};

static int cmp(const void *a_ptr, const void *b_ptr) {
    const struct cell a = *(struct cell*)a_ptr;
    const struct cell b = *(struct cell*)b_ptr;

    if (a.sum != b.sum) { return (a.sum > b.sum) - (a.sum < b.sum); }

    if (a.num != b.num) { return (a.num > b.num) - (a.num < b.num); }

    return (a.idx > b.idx) - (a.idx < b.idx);
}

int minSwaps(const int *restrict nums, const int len) {
    struct cell *restrict arr = malloc((size_t)len * sizeof(*arr));
    if (arr == NULL) { return -1; }

    for (int i = 0; i < len; i += 1) {
        int sum = 0;
        int tmp = nums[i];
        while (tmp > 0) {
            sum += tmp % 10;
            tmp /= 10;
        }
        arr[i].sum = sum;
        arr[i].num = nums[i];
        arr[i].idx = i;
    }

    qsort(arr, (size_t)len, sizeof(*arr), cmp);
    int total = len;

    for (int i = 0; i < len; i += 1) {
        if (arr[i].sum != INVALID_SUM) {
            total -= 1;
            int j = i;
            while (arr[j].sum != INVALID_SUM) {
                arr[j].sum = INVALID_SUM;
                j = arr[j].idx;
            }
        }
    }

    return total;
}
