constexpr size_t freqs_len = 26;

static inline void calc_freqs(const string_view s, span<uint8_t> res) {
    for (const char ch : s) {
        assert(ch >= 'a' && ch <= 'z' && res[ch - 'a'] < numeric_limits<uint8_t>::max());
        res[ch - 'a'] += 1;
    }
}

class Solution {
public:
    static vector<string> wordSubsets(const vector<string>& words1, const vector<string>& words2) {
        auto res = vector<string>();
        uint8_t max_freqs2[freqs_len] = { 0 };
        for (const auto& w : words2) {
            uint8_t freqs[freqs_len] = { 0 };
            calc_freqs(w, freqs);
            for (size_t i = 0; i < freqs_len; i += 1) {
                max_freqs2[i] = std::max(max_freqs2[i], freqs[i]);
            }
        }

        for (const auto& w : words1) {
            uint8_t freqs[freqs_len] = { 0 };
            calc_freqs(w, freqs);
            bool is_valid = true;

            for (size_t i = 0; i < freqs_len; i += 1) {
                if (max_freqs2[i] > freqs[i]) {
                    is_valid = false;
                    break;
                }
            }

            if (is_valid) {
                res.push_back(w);
            }
        }

        return res;
    }
};
