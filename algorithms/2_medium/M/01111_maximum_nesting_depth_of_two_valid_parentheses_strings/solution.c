/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxDepthAfterSplit(const char *restrict seq, int* return_len) {
    const size_t len = strlen(seq);
    int *restrict res = malloc(len * sizeof(*res));
    if (res == NULL) {
        perror("alloc fail");
        *return_len = -1;
        return NULL;
    }
    ptrdiff_t balance = 0;

    for (size_t i = 0; i < len; i += 1) {
        switch (seq[i]) {
            case '(':
                balance += 1;
                if ((balance & 1) == 1) {
                    res[i] = 0;
                } else {
                    res[i] = 1;
                }
                break;
            case ')':
                if ((balance & 1) == 1) {
                    res[i] = 0;
                } else {
                    res[i] = 1;
                }
                balance -= 1;
                break;
            default:
                perror("invalid input");
                free(res);
                *return_len = -1;
                return NULL;
        }
    }

    *return_len = (int)len;
    return res;
}
