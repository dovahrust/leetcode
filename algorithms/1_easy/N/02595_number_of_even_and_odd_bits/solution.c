/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* evenOddBit(int n, int* return_len) {
    if (n < 0 || return_len == NULL) {
        fprintf(stderr, "invalid input");
        exit(1);
    }
    int odd = 0;
    int even = 0;
    bool is_odd = true;

    while (n > 0) {
        if ((n & 1) == 1) {
            if (is_odd) {
                odd += 1;
            } else {
                even += 1;
            }
        }

        is_odd = !is_odd;
        n >>= 1;
    }

    int* res = malloc(2 * sizeof(*res));
    if (res == NULL) {
        fprintf(stderr, "alloc fail");
        exit(1);
    }
    res[0] = odd;
    res[1] = even;
    *return_len = 2;
    return res;
}
