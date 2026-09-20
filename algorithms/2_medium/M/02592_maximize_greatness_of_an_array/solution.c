static int cmp(const void *a_ptr, const void *b_ptr) {
    const int a = *(const int*)a_ptr;
    const int b = *(const int*)b_ptr;

    return (a > b) - (a < b);
}

int maximizeGreatness(int *restrict nums, const int len) {
    qsort(nums, (size_t)len, sizeof(*nums), cmp);

    int lo = 0;

    for (int hi = 0; hi < len; hi += 1) {
        if (nums[hi] > nums[lo]) {
            lo += 1;
        }
    }

    return lo;
}
