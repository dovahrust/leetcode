inline static int cmp(const void *a_ptr, const void *b_ptr) {
    const int a = *(const int *)a_ptr;
    const int b = *(const int *)b_ptr;

    return (a > b) - (a < b);
}

long long minimumRemoval(int *restrict beans, const int len) {
    qsort(beans, (size_t)len, sizeof(*beans), cmp);
    int64_t total = 0;
    for (int i = 0; i < len; i += 1) { total += beans[i]; }
    int64_t best = total;

    for (int i = 0; i < len; i += 1) {
        const int64_t w_suff = len - i;
        const int64_t can_keep = w_suff * beans[i];
        best = MIN(best, total - can_keep);
    }

    return best;
}
