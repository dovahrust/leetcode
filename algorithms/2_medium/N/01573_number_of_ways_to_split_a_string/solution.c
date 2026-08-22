#define MOD 1000000007

int numWays(const char *restrict s) {
    if (s == NULL) { return 0; }
    const size_t len = strlen(s);
    if (len <= 2) { return 0; }

    size_t ones = 0;
    for (size_t i = 0; i < len; i += 1) {
        if (s[i] == '1') {
            ones += 1;
        }
    }

    if (ones == 0) {
        const size_t n = len - 2;
        return (int)((n * (n + 1) / 2) % MOD);
    }

    if (ones % 3 != 0) {
        return 0;
    }

    const size_t spot1 = ones / 3;
    const size_t spot2 = spot1 * 2;
    size_t curr_ones = 0;
    size_t cnt1 = 0;
    size_t cnt2 = 0;

    for (size_t i = 0; i < len; i += 1) {
        if (s[i] == '1') {
            curr_ones += 1;
            if (curr_ones > spot2) {
                break;
            }
        } else if (curr_ones == spot1) {
            cnt1 += 1;
        } else if (curr_ones == spot2) {
            cnt2 += 1;
        }
    }

    return (int)(((cnt1 + 1) * (cnt2 + 1)) % MOD);
}
