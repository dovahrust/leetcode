/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* grayCode(const int n, int* return_len)
{
    assert(n >= 1 && n <= 16);
    const int len = (1 << n);
    int* res = malloc((size_t)len * sizeof(*res));
    assert(res != NULL);
    *return_len = len;

    for (int i = 0; i < len; i += 1) {
        res[i] = (i ^ (i >> 1));
    }

    return res;
}
