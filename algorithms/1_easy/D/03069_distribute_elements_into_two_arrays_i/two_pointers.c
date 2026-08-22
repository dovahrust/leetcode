__attribute__((no_sanitize("all")))
static inline void rev(int *restrict begin, int *restrict end) {
    while (begin + 1 < end) {
        end -= 1;

        const int temp = *begin;
        *begin = *end;
        *end = temp;

        begin += 1;
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
__attribute__((no_sanitize("all")))
int* resultArray(const int *restrict nums, const int len, int *restrict return_len) {
    if (return_len == NULL) { exit(1); }

    if (len < 3 || nums == NULL) {
        *return_len = -1;
        return NULL;
    }

    int *restrict res = malloc((size_t)len * sizeof(*nums));
    if (res == NULL) {
        *return_len = -1;
        return NULL;
    }

    int hi = len - 1;
    res[hi] = nums[1];
    int lo = 0;
    res[lo] = nums[0];

    for (int i = 2; i < len; i += 1) {
        if (res[hi] > res[lo]) {
            hi -= 1;
            res[hi] = nums[i];
        } else {
            lo += 1;
            res[lo] = nums[i];
        }
    }

    rev(res + hi, res + len);

    *return_len = len;
    return res;
}
