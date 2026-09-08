#define MOD 1000000007

int numOfSubarrays(const int *restrict arr, const int len) {
    int32_t cnt = 0;
    int32_t odd = 0;
    int32_t even = 1;
    int32_t sum = 0;

    for (int i = 0; i < len; i += 1) {
        sum += arr[i];

        if ((sum & 1) == 1) {
            cnt = (cnt + even) % MOD;
            odd += 1;
        } else {
            cnt = (cnt + odd) % MOD;
            even += 1;
        }
    }

    return (int)cnt;
}
