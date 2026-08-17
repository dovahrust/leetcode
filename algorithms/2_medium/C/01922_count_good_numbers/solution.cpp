constexpr long long MOD = 1'000'000'007;

class Solution {
    inline static long long pow_by_mod(long long base, long long expo, const long long mod_by) {
        long long res = 1;
        while (expo > 0) {
            if ((expo & 1) == 1) {
                res = (res * base) % mod_by;
            }
            base = (base * base) % mod_by;
            expo >>= 1;
        }
        return res;
    }
public:
    static int countGoodNumbers(const long long n) {
        if (n <= 0) { return -1; }

        const long long half = n / 2;

        const long long odd = pow_by_mod(4, half, MOD);
        const long long even = pow_by_mod(5, n - half, MOD);
        const long long res = (odd * even) % MOD;

        return static_cast<int>(res);
    }
};
