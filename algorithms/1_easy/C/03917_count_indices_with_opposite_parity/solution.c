/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countOppositeParity(const int *restrict nums, const int len, int *restrict return_len) {
    int *restrict res = malloc((size_t)len * sizeof(*res));
    if (res == NULL) {
        *return_len = -1;
        return NULL;
    }

    int o = 0;
    int e = 0;

    for (int i = len - 1; i >= 0; i -= 1) {
        if ((nums[i] & 1) == 1) {
            o += 1;
            res[i] = e;
        } else {
            e += 1;
            res[i] = o;
        }
    }

    *return_len = len;
    return res;
}
