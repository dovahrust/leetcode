class Solution {
public:
    static bool doesAliceWin(const string& s) {
        return any_of(s.begin(), s.end(), [](const char ch) {
            return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
        });
    }
};
