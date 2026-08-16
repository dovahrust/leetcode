bool mergeTriplets(
    int *restrict *restrict triplets, const int triplets_len, const int *restrict triplets_cols,
    const int *restrict target, const int target_len
) {
    bool seen_0 = false;
    bool seen_1 = false;
    bool seen_2 = false;

    for (int i = 0; i < triplets_len; i += 1) {
        const int *restrict t = triplets[i];

        if (t[0] <= target[0] && t[1] <= target[1] && t[2] <= target[2]) {
            seen_0 |= (t[0] == target[0]);
            seen_1 |= (t[1] == target[1]);
            seen_2 |= (t[2] == target[2]);
        }

        if (seen_0 && seen_1 && seen_2) {
            return true;
        }
    }

    return false;
}
