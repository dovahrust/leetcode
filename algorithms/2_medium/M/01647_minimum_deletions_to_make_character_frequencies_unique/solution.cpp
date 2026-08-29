class Solution {
public:
    static int minDeletions(const string& s) {
        const size_t len = s.size();
        size_t freqs[256] = { 0 };
        for (size_t i = 0; i < len; i += 1) {
            freqs[(unsigned char)s[i]] += 1;
        }
        ranges::sort(freqs, [](const size_t a, const size_t b) {
            return a > b;
        });

        size_t cnt = 0;
        size_t prev = freqs[0];
        for (size_t i = 1; i < 256; i += 1) {
            if (freqs[i] == 0) {
                break;
            }

            if (prev > 0) {
                prev -= 1;
            }

            if (freqs[i] > prev) {
                cnt += freqs[i] - prev;
            }

            prev = std::min(prev, freqs[i]);
        }

        assert(cnt <= static_cast<size_t>(INT_MAX));
        return static_cast<int>(cnt);
    }
};
