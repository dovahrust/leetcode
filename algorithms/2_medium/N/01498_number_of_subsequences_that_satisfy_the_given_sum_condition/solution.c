#define MOD 1000000007

inline static int64_t pow_with_mod(int64_t base, int64_t pow, const int64_t mod_by) {
    int64_t res = 1;
    while (pow > 0) {
        if ((pow & 1) == 1) {
            res = (res * base) % mod_by;
        }
        base = (base * base) % mod_by;
        pow >>= 1;
    }
    return res;
}

static int cmp(const void *a_ptr, const void *b_ptr) {
    const int a = *(int*)a_ptr;
    const int b = *(int*)b_ptr;

    return (a > b) - (a < b);
}

int numSubseq(const int *restrict nums, const int len, const int target) {
    if (nums == NULL || len <= 0) { return 0; }

    qsort(nums, (size_t)len, sizeof(*nums), cmp);
    int64_t cnt = 0;
    int64_t lo = 0;
    int64_t hi = len - 1;

    while (lo <= hi) {
        if (nums[lo] + nums[hi] > target) {
            hi -= 1;
        } else {
            cnt = (cnt + pow_with_mod(2, hi - lo, MOD)) % MOD;
            lo += 1;
        }
    }

    return (int)cnt;
}
