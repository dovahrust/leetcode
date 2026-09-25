#define K_MAX 5
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
long long* resultArray(const int *restrict nums, const int len, int k, int *return_len) {
    assert(k >= 1 && k <= K_MAX && return_len != NULL);
    long long *restrict res = malloc((size_t)k * sizeof(*res));
    if (res == NULL) {
        *return_len = -1;
        return NULL;
    }
    long long prev[K_MAX] = { 0 };
    long long sum[K_MAX] = { 0 };
    for (int i = 0; i < len; i += 1) {
        long long curr[K_MAX] = { 0 };
        const int rem = nums[i] % k;
        curr[rem] += 1;
        for (int j = 0; j < k; j += 1) {
            curr[(j * rem) % k] += prev[j];
        }
        for (int j = 0; j < k; j += 1) {
            sum[j] += curr[j];
            prev[j] = curr[j];
        }
    }

    for (int i = 0; i < k; i += 1) {
        res[i] = sum[i];
    }
    *return_len = k;
    return res;
}
