constexpr size_t MOD = 1'000'000'007;

class Solution {
public:
    static int numWays(const string& s) {
        const size_t len = s.size();
        if (len <= 2) { return 0; }

        size_t ones = 0;
        for (const char ch : s) {
            if (ch == '1') {
                ones += 1;
            }
        }

        if (ones == 0) {
            const size_t n = len - 2;
            return static_cast<int>((n * (n + 1) / 2) % MOD);
        }

        if (ones % 3 != 0) {
            return 0;
        }

        const size_t spot1 = ones / 3;
        const size_t spot2 = spot1 * 2;
        size_t curr_ones = 0;
        size_t cnt1 = 0;
        size_t cnt2 = 0;

        for (const char ch : s) {
            if (ch == '1') {
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

        return static_cast<int>(((cnt1 + 1) * (cnt2 + 1)) % MOD);
    }
};
