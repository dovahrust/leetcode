static int cmp(const void *a_ptr, const void *b_ptr) {
    const int a = *(const int*)a_ptr;
    const int b = *(const int*)b_ptr;

    return (a > b) - (a < b);
}

int maximumBags(
    const int *capacity, const int capacity_len,
    const int *rocks, const int rocks_len,
    int additional_rocks
) {
    const int n = capacity_len;
    int *restrict needs = malloc((size_t)n * sizeof(*needs));

    for (int i = 0; i < n; i += 1) {
        needs[i] = capacity[i] - rocks[i];
    } 

    qsort(needs, (size_t)n, sizeof(*needs), cmp);

    int cnt = 0;
    for (int i = 0; i < n; i += 1) {
        if (needs[i] > additional_rocks) {
            break;
        }

        additional_rocks -= needs[i];
        cnt += 1;
    }

    free(needs);
    return cnt;
}
