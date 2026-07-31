constexpr size_t freqs_len = 26;

class Solution {
public:
    static int minimumPushes(const string& word) {
        auto freqs = array<int, freqs_len>();

        for (const auto ch : word) {
            assert(ch >= 'a' && ch <= 'z');
            freqs[ch - 'a'] += 1;
        }

        sort(freqs.rbegin(), freqs.rend());

        int total_cost = 0;

        for (size_t i = 0; i < freqs_len; i += 1) {
            const int curr_cost = 1 + i / 8;
            total_cost += freqs[i] * curr_cost;
        }

        return total_cost;
    }
};
