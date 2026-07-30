static inline int max_int(const int a, const int b)
{
    return a > b ? a : b;
}

int maxFreeTime(
    const int event_time,
    const int k,
    const int* start_time,
    const int start_time_len,
    const int* end_time,
    const int end_time_len
) {
    assert(start_time_len >= 2 && start_time_len == end_time_len && k >= 1 && event_time >= 1);
    assert(start_time != NULL && end_time != NULL);
    const int len = start_time_len;

    int* prefix = malloc(((size_t)len + 2U) * sizeof(*prefix));
    assert(prefix != NULL);
    prefix[0] = 0;
    int prev_end = 0;
    for (int i = 0; i < len; i += 1) {
        prefix[i + 1] = prefix[i] + start_time[i] - prev_end;
        prev_end = end_time[i];
    }
    prefix[len + 1] = event_time - prev_end + prefix[len];

    int res = 0;
    for (int i = k - 1; i < len; i += 1) {
        const int curr = prefix[i + 2] - prefix[i - (k - 1)];
        res = max_int(res, curr);
    }

/* cleanup: */
    free(prefix);
    return res;
}
