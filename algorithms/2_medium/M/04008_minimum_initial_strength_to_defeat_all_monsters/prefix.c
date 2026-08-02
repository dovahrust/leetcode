long long minInitialStrength(
    const int* monsters, const int monsters_len,
    int** boosts, const int boosts_len, const int* boosts_cols_data
) {
    if (monsters == NULL || monsters_len <= 0) {
        fprintf(stderr, "invalid input");
        goto err;
    }

    if (boosts_len > 0 && (boosts == NULL || boosts_cols_data == NULL)) {
        fprintf(stderr, "invalid input");
        goto err;
    }

    int64_t* prefix = calloc(((size_t)monsters_len + 1), sizeof(*prefix));
    if (prefix == NULL) {
        fprintf(stderr, "alloc fail");
        goto err;
    }

    for (int i = 0; i < boosts_len; i += 1) {
        if (boosts_cols_data[i] != 3) {
            fprintf(stderr, "invalid input");
            goto cleanup_err;
        }
        const int* b = boosts[i];
        const int l = b[0];
        const int r = b[1];
        const int v = b[2];
        if (l < 0 || r < l || v < 0 || r >= monsters_len) {
            fprintf(stderr, "invalid input");
            goto cleanup_err;
        }
        prefix[l] += v;
        prefix[r + 1] -= v;
    }

    for (int i = 1; i < monsters_len; i += 1) {
        prefix[i] += prefix[i - 1];
    }

    int idx = monsters_len - 1;
    while (idx >= 0 && prefix[idx] >= monsters[idx]) {
        idx -= 1;
    }

    int64_t curr = 0;
    if (idx >= 0) {
        curr += monsters[idx] - prefix[idx];
        idx -= 1;
    }
    while (idx >= 0) {
        curr += monsters[idx];
        idx -= 1;
    }

/* cleanup_ok: */
    free(prefix);
    return curr;

cleanup_err:
    free(prefix);
err:
    exit(1);
}
