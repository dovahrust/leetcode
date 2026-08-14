class Solution {
public:
    static int maximumLengthSubstring(const string& s) {
        const size_t len = s.size();
        int8_t freqs[256] = { 0 };
        size_t lo = 0;
        size_t max = 0;

        for (size_t hi = 0; hi < len; hi += 1) {
            const unsigned char ch_hi = static_cast<unsigned char>(s[hi]);
            freqs[ch_hi] += 1;

            while (freqs[ch_hi] > 2) {
                const unsigned char ch_lo = static_cast<unsigned char>(s[lo]);
                freqs[ch_lo] -= 1;
                lo += 1;
            }

            max = std::max(max, hi + 1 - lo);
        }

        return static_cast<int>(max);
    }
};
