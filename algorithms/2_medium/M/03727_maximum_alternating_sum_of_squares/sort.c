static int cmp(const void *a_ptr, const void *b_ptr) {
    const int a = ABS(*(const int*)a_ptr);
    const int b = ABS(*(const int*)b_ptr);
    return (a > b) - (a < b);
}

long long maxAlternatingSum(int *restrict nums, const int len) {
    qsort(nums, len, sizeof(*nums), cmp);

    const int plus_index = len / 2;
    int64_t t_sum = 0;

    for (int i = 0; i < plus_index; i += 1) { t_sum -= (int64_t)nums[i] * (int64_t)nums[i]; }

    for (int i = plus_index; i < len; i += 1) { t_sum += (int64_t)nums[i] * (int64_t)nums[i]; }

    return t_sum;
}
