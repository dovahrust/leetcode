long long numberOfWeeks(const int *restrict milestones, const int len) {
    if (len <= 0 || milestones == NULL) { goto invalid_input; }

    long long max = INT_MIN;
    long long sum = 0;

    for (int i = 0; i < len; i += 1) {
        if (milestones[i] <= 0) {
            goto invalid_input;
        }
        max = MAX(max, milestones[i]);
        sum += milestones[i];
    }

    const long long sum_rest = sum - max;

    return sum_rest + MIN(sum_rest + 1, max);

invalid_input:
    return -1;
}
