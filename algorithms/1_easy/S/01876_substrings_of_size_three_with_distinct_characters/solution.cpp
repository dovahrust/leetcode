class Solution {
public:
    static int countGoodSubstrings(const string& s) {
        const size_t len = s.size();
        size_t cnt = 0;

        for (size_t i = 2; i < len; i += 1) {
            if (s[i] != s[i - 1] && s[i] != s[i - 2] && s[i - 1] != s[i - 2]) {
                cnt += 1;
            }
        }

        if (cnt > static_cast<size_t>(numeric_limits<int>::max())) { return -1; }

        return static_cast<int>(cnt);
    }
};
