#define MOD 1000000007

static inline bool is_prime(const int n) {
    if (n <= 1) {
        return false;
    }
    const int sq = (int)sqrt(n);
    for (int i = 2; i <= sq; i += 1) {
        if ((n % i) == 0) {
            return false;
        }
    }
    return true;
}

static inline int64_t fact_with_mod(const int64_t n) {
    int64_t res = 1;
    for (int64_t i = 2; i <= n; i += 1) {
        res = (res * i) % MOD;
    }
    return res;
}

int numPrimeArrangements(int n) {
    int64_t p = 0;
    int64_t o = 0;
    for (int i = 1; i <= n; i += 1) {
        if (is_prime(i)) {
            p += 1;
        } else {
            o += 1;
        }
    }

    const int64_t res = fact_with_mod(p) * fact_with_mod(o);

    return (int)(res % MOD);
}
