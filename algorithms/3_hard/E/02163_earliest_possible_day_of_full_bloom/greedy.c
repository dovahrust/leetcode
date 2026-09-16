struct pair {
    int pt;
    int gt;
};

static int cmp(const void *a_ptr, const void *b_ptr) {
    const struct pair a = *(const struct pair*)a_ptr;
    const struct pair b = *(const struct pair*)b_ptr;

    return (a.gt < b.gt) - (a.gt > b.gt);
}

int earliestFullBloom(
    const int *plant_time, const int plant_time_len,
    const int *grow_time, const int grow_time_len
) {
    const int n = plant_time_len;
    struct pair *restrict combo = malloc((size_t)n * sizeof(*combo));
    if (combo == NULL) { return -1; }

    for (int i = 0; i < n; i +=1) {
        combo[i] = (struct pair){ .pt = plant_time[i], .gt = grow_time[i] };
    }

    qsort(combo, (size_t)n, sizeof(*combo), cmp);

    int res = 0;
    int prev_gt = 0;

    for (int i = 0; i < n; i +=1) {
        const int pt = combo[i].pt;
        const int gt = combo[i].gt;

        if (pt + gt > prev_gt) {
            res += pt + gt - prev_gt;
            prev_gt = gt;
        } else {
            prev_gt = prev_gt - pt;
        }
    }

    free(combo);
    return res;
}
