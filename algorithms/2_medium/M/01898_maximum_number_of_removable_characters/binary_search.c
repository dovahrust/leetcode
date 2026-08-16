inline static bool is_ok(
    const char *restrict s, const size_t s_len,
    const char *restrict p, const size_t p_len,
    const bool *restrict can_use
) {
    size_t s_idx = 0;
    size_t p_idx = 0;
    while (s_idx < s_len && p_idx < p_len) {
        if (can_use[s_idx] && s[s_idx] == p[p_idx]) {
            p_idx += 1;
        }

        s_idx += 1;
    }

    return p_idx == p_len;
}

int maximumRemovals(
    const char *restrict s,
    const char *restrict p,
    const int *restrict removable, const int removable_len
) {
    if (s == NULL || p == NULL || removable_len < 0 || (removable != 0 && removable == NULL)) { return -1; }

    if (removable_len == 0) { return 0; }

    const size_t s_len = strlen(s);
    const size_t p_len = strlen(p);

    if (s_len == 0 || p_len == 0) { return -1; }

    int lo = 0;
    int hi = removable_len - 1;
    bool *restrict can_use = malloc(s_len * sizeof(*can_use));
    if (can_use == NULL) { return -1; }

    while (lo <= hi) {
        const int mid = lo + (hi - lo) / 2;

        for (size_t i = 0; i < s_len; i += 1) { can_use[i] = true; }

        for (int i = 0; i <= mid; i += 1) {
            can_use[removable[i]] = false;
        }

        if (is_ok(s, s_len, p, p_len, can_use)) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    return hi + 1;
}
