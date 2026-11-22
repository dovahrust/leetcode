static int cmp(const void *a_ptr, const void *b_ptr) {
    const int a = *(const int*)a_ptr;
    const int b = *(const int*)b_ptr;

    return (a > b) - (a < b);
}

int minMoves2(int *restrict nums, const int len) {
    qsort(nums, (size_t)len, sizeof(*nums), cmp);
    const int median = nums[len / 2];
    int cost = 0;

    for (int i = 0; i < len; i += 1) { cost += ABS(nums[i] - median); }

    return cost;
}
