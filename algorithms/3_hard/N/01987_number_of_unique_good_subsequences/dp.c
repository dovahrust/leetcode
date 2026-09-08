#define MOD 1000000007

int numberOfUniqueGoodSubsequences(const char *restrict binary) {
    if (binary == NULL) { return 0; }
    int32_t end_zero = 0;
    int32_t end_one = 0;
    bool has_zero = false;

    for (size_t i = 0; binary[i] != '\0'; i += 1) {
        switch (binary[i]) {
            case '0':
                has_zero = true;
                end_zero = (end_zero + end_one) % MOD;
                break;
            case '1':
                end_one = (end_zero + end_one + 1) % MOD;
                break;
            default:
                return -1;
        }
    }

    if (has_zero) {
        return (int)((end_zero + end_one + 1) % MOD);
    } else {
        return (int)end_one;
    }
}
