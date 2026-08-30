typedef ptrdiff_t isize;

class Solution {
public:
    static string minWindow(const string& s, const string& t) {
        const isize s_len = std::ssize(s);
        if (s_len < std::ssize(t)) { return string(); }
        isize freqs[256] = { 0 };

        for (const unsigned char ch : t) {
            freqs[ch] -= 1;
        }

        isize missing_distinct = 0;
        for (isize i = 0; i < 256; i += 1) {
            if (freqs[i] != 0) {
                missing_distinct += 1;
            }
        }
        isize lo = 0;
        auto res = span<const char>(&s[0], 0);

        for (isize hi = 0; hi < s_len; hi += 1) {
            freqs[static_cast<unsigned char>(s[hi])] += 1;
            if (freqs[static_cast<unsigned char>(s[hi])] == 0) {
                missing_distinct -= 1;
            }

            while (lo <= hi && freqs[static_cast<unsigned char>(s[lo])] > 0) {
                freqs[static_cast<unsigned char>(s[lo])] -= 1;
                lo += 1;
            }

            if (missing_distinct == 0 && (res.empty() || std::ssize(res) > (hi + 1 - lo))) {
                res = span<const char>(&s[lo], (hi + 1) - lo);
                // Remove leftmost required char to continue searching for a smaller window
                freqs[static_cast<unsigned char>(s[lo])] -= 1;
                lo += 1;
                missing_distinct += 1;
            }
        }

        return string(res.cbegin(), res.cend());
    }
};
