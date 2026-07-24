static inline int gray_to_bin(int g)
{
    int res = g;
    while (g != 0) {
        g >>= 1;
        res ^= g;
    }
    return res;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* circularPermutation(int n, int start, int* return_len)
{
    assert(n >= 1 && n <= 16);
    const int cnt = 1 << n;
    int* res = malloc((size_t)cnt * sizeof(*res));
    assert(res != NULL);
    *return_len = cnt;
    int curr = gray_to_bin(start);

    for (int i = 0; i < cnt; i+= 1) {
        res[i] = curr ^ (curr >> 1);
        curr = (curr + 1) % cnt;
    }

    return res;
}
