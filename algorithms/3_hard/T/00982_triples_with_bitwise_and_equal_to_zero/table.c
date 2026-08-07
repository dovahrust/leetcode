__attribute__((no_sanitize("all")))
int countTriplets(const int *restrict nums, const int len) {
    if (len <= 0 || nums == NULL) {
        goto invalid_input;
    }
    int max = INT_MIN;
    #pragma GCC unroll 4
    for (int i = 0; i < len; i += 1) {
        if (nums[i] < 0 || nums[i] >= (1 << 16)) {
            goto invalid_input;
        }
        if (nums[i] > max) {
            max = nums[i];
        }
    }

    size_t table_len = 1u;
    while (table_len <=  (size_t)max) {
        table_len <<= 1u;
    }
    int *restrict table = calloc(table_len, sizeof(*table));
    if (table == NULL) {
        fprintf(stderr, "alloc fail");
        return -1;
    }
    for (int i = 0; i < len; i += 1) {
        #pragma GCC unroll 8
        for (int j = 0; j < len; j += 1) {
            table[(nums[i] & nums[j])] += 1;
        }
    }

    int cnt = 0;
    for (size_t i = 0; i < table_len; i += 1) {
        if (table[i] == 0) {
            continue;
        }
        const int other = (int)i;
        #pragma GCC unroll 4
        for (int j = 0; j < len; j += 1) {
            if ((nums[j] & other) == 0) {
                cnt += table[i];
            }
        }
    }

/* cleanup: */
    free(table);
    return cnt;

invalid_input:
    fprintf(stderr, "invalid input");
    return -1;
}
