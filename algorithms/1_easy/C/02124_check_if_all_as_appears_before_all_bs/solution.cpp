class Solution {
public:
    static bool checkString(const string& s) {
        bool seen_b = false;
        for (const auto ch : s) {
            if (ch == 'b') {
                seen_b = true;
            } else if (seen_b) {
                return false;
            }
        }

        return true;
    }
};
