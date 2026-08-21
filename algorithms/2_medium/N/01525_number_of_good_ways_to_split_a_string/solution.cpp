class Solution {
public:
    static int numSplits(const string& s) {
        if (s.size() <= 1) { return 0; }

        const size_t len = s.size();
        int cnt_right = 0;
        size_t freqs_right[256] = { 0 };
        for (const unsigned char ch : s) {
            if (freqs_right[ch] == 0) {
                cnt_right += 1;
            }
            freqs_right[ch] += 1;
        }

        size_t freqs_left[256] = { 0 };
        int cnt_left = 0;

        size_t res = 0;
        for (const unsigned char ch : s) {
            if (cnt_left == cnt_right) {
                res += 1;
            }

            freqs_right[ch] -= 1;
            if (freqs_right[ch] == 0) {
                cnt_right -= 1;
            }

            if (freqs_left[ch] == 0) {
                cnt_left += 1;
            }
            freqs_left[ch] += 1;
        }

        if (res > static_cast<size_t>(numeric_limits<int>::max())) { return -1; }
        return static_cast<int>(res);
    }
};
