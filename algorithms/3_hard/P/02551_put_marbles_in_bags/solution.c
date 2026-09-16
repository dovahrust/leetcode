static int cmp(const void *a_ptr, const void *b_ptr) {
    const int a = *(const int*)a_ptr;
    const int b = *(const int*)b_ptr;
    return (a > b) - (a < b);
}

long long putMarbles(const int *restrict weights, const int weights_len, const int k) {
    if (k >= weights_len || k == 1) { return 0; }

    const int scores_len = weights_len - 1; 
    int *restrict scores = malloc((size_t)scores_len * sizeof(*scores));
    if (scores == NULL) { return -1; }

    for (int i = 0; i < weights_len - 1; i += 1) {
        scores[i] = weights[i] + weights[i + 1];
    }

    qsort(scores, (size_t)scores_len, sizeof(*scores), cmp);

    int64_t max = 0;
    int64_t min = 0;

    for (int i = 0; i < (k - 1); i += 1) {
        max += scores[scores_len - i - 1];
        min += scores[i];
    }

    free(scores);
    return max - min;
}
