class Solution {
public:
    static vector<int> findAnagrams(const string& s, const string& p) {
        if (p.size() > s.size()) { return vector<int>(); }

        size_t freqs_p[256] = { 0 };
        for (const unsigned char ch : p) {
            freqs_p[ch] += 1;
        }

        const size_t s_len = s.size();
        const size_t p_len = p.size();
        size_t freqs_window[256] = { 0 };
        auto res = vector<int>();
        size_t lo = 0;

        for (size_t hi = 0; hi < s_len; hi += 1) {
            const size_t idx_bytes_hi = static_cast<unsigned char>(s[hi]);
            freqs_window[idx_bytes_hi] += 1;

            while (freqs_window[idx_bytes_hi] > freqs_p[idx_bytes_hi]) {
                freqs_window[static_cast<unsigned char>(s[lo])] -= 1;
                lo += 1;
            }

            if (hi - lo + 1 == p_len) {
                res.push_back(static_cast<int>(lo));
            }
        }

        return res;
    }
};
