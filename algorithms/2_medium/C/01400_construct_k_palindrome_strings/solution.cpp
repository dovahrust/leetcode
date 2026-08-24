class Solution {
public:
    static bool canConstruct(const string& s, const int k_int) {
        assert(k_int >= 1);
        const size_t k = static_cast<size_t>(k_int);
        const size_t len = s.size();

        if (k > len) { return false; }

        size_t freqs[256] = { 0 };

        for (const unsigned char ch : s) {
            freqs[ch] += 1;
        }

        size_t cnt_odd = 0;
        for (size_t i = 0; i < 256; i += 1) {
            if ((freqs[i] & 1) == 1) {
                cnt_odd += 1;
            }
        }

        return cnt_odd <= k;
    }
};
