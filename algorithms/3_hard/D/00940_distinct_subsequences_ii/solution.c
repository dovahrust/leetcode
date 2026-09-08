#define MOD 1000000007

int distinctSubseqII(const char *restrict s) {
    if (s == NULL) { return 0; }

    int64_t end_with[256] = { 0 };
    int64_t cnt = 0;

    for (size_t i = 0; s[i] != '\0'; i += 1) {
        const int64_t new_end_with = (cnt + 1) % MOD;
        const int64_t old_end_with = end_with[(unsigned char)s[i]];
        cnt = ((cnt - old_end_with) + new_end_with + MOD) % MOD;
        end_with[(unsigned char)s[i]] = new_end_with;
    }

    return (int)cnt;
}
