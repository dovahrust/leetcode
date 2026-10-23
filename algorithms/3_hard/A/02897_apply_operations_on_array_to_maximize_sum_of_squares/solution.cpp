constexpr uint64_t MOD = 1'000'000'007;
constexpr uint64_t INF = numeric_limits<uint64_t>::max();

class Solution {
public:
    static int maxSum(const vector<int>& nums, const int k_i32) {
        assert(k_i32 >= 1 && k_i32 <= std::ssize(nums));
        uint64_t freqs[32] = { 0 };

        for (const int num_i32 : nums) {
            const uint32_t num = static_cast<uint32_t>(num_i32);
            for (uint32_t i = 0; i < 32; i += 1) {
                const uint32_t mask = (1 << i);
                if ((mask & num) != 0) {
                    freqs[i] += 1;
                }
            }
        }

        uint64_t res = 0;
        uint64_t k = static_cast<uint64_t>(k_i32);
        while (k > 0) {
            uint64_t min_freq_non_zero = INF;
            uint64_t curr = 0;
            for (uint64_t i = 0; i < 32; i += 1) {
                if (freqs[i] != 0) {
                    min_freq_non_zero = std::min(min_freq_non_zero, freqs[i]);
                    const uint64_t mask = (1 << i);
                    curr |= mask;
                }
            }
            min_freq_non_zero = std::min(min_freq_non_zero, k);
            k -= min_freq_non_zero;
            const uint64_t base = (curr * curr) % MOD;
            res = (res + base * min_freq_non_zero) % MOD;

            for (uint64_t i = 0; i < 32; i += 1) {
                if (freqs[i] != 0) {
                    freqs[i] -= min_freq_non_zero;
                }
            }
        }

        return static_cast<int>(res);
    }
};
