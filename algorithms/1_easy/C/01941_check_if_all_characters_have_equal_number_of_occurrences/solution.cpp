class Solution {
public:
    static bool areOccurrencesEqual(const string& s) {
        if (s.empty()) { return true; }
        size_t freqs[256] = { 0 };

        for (const unsigned char ch : s) {
            freqs[ch] += 1;
        }

        const size_t freq_first = freqs[static_cast<unsigned char>(s[0])];
        for (size_t i = 0; i < 256; i += 1) {
            if (freqs[i] != 0 && freqs[i] != freq_first) {
                return false;
            }
        }

        return true;
    }
};
