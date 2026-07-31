constexpr size_t freqs_len = 256;

class Solution {
public:
    static int longestPalindrome(const string& s) {
        const size_t len = s.size();
        if (len > 2000) {
            fprintf(stderr, "invalid input: len should be less than 2_000");
            exit(1);
        }

        int16_t freqs[freqs_len] = { 0 };

        for (const char ch : s) {
            freqs[(unsigned char)(ch)] += 1;
        }

        int cnt = 0;

        for (size_t i = 0; i < freqs_len; i += 1) {
            cnt += freqs[i] - (freqs[i] & 1);
        }

        return std::min(cnt + 1, static_cast<int>(len));
    }
};
