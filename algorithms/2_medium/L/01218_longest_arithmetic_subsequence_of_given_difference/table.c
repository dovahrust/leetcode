#define MAX_ALOWED_NUM 10000
#define MIN_ALOWED_NUM -10000
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int longestSubsequence(int* arr, const int len, const int difference) {
    assert(len > 0 && arr != NULL);
    if (len == 1) { return 1; }

    int max = INT_MIN;
    int min = INT_MAX;

    for (int i = 0; i < len; i += 1) {
        max = MAX(max, arr[i]);
        min = MIN(min, arr[i]);
    }
    assert(min >= MIN_ALOWED_NUM && max <= MAX_ALOWED_NUM);

    const size_t table_len = (size_t)(max - min + 1);
    int* table = calloc(table_len, sizeof(*table));
    assert(table != NULL);
    int res = 0;

    for (int i = 0; i < len; i += 1) {
        const int a = arr[i];
        int curr = 1;
        if (a - difference >= min && a - difference <= max) {
            const size_t idx = (size_t)(a - difference - min);
            curr = 1 + table[idx];
        }

        table[a - min] = curr;
        res = MAX(res, curr);
    }

/* cleanup: */
    free(table);
    return res;
}
