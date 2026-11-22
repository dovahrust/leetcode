class Solution {
public:
    static int minChanges(const string& s) {
        const size_t len = s.size();
        int cnt = 0;

        for (size_t i = 1; i < len; i += 2) {
            if (s[i] != s[i - 1]) {
                cnt += 1;
            }
        }

        return cnt;
    }
};
