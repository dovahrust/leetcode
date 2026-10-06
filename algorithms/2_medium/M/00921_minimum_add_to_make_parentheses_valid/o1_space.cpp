class Solution {
public:
    static int minAddToMakeValid(const string& s) {
        size_t res = 0;
        size_t open_cnt = 0;

        for (const char ch : s) {
            if (ch == '(') {
                open_cnt += 1;
            } else {
                if (open_cnt > 0 ) {
                    open_cnt -= 1;
                } else {
                    res += 1;
                }
            }
        }

        return static_cast<int>(res + open_cnt);
    }
};
