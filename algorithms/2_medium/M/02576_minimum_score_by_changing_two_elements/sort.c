static int cmp(const void *a_ptr, const void *b_ptr) {
    const int a = *(const int*)a_ptr;
    const int b = *(const int*)b_ptr;

    return (a > b) - (a < b);
}

int minimizeSum(int *restrict nums, const int len) {
    if (len <= 2) { return 0; }

    qsort(nums, (size_t)len, sizeof(*nums), cmp);
    const int c1 = nums[len - 3] - nums[0];
    const int c2 = nums[len - 2] - nums[1];
    const int c3 = nums[len - 1] - nums[2];

    return MIN(c1, MIN(c2, c3));
}
