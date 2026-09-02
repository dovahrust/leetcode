class Solution {
public:
    static bool checkZeroOnes(const string& s) {
        size_t lonegst_one = 0;
        size_t longest_zero = 0;
        size_t curr_one = 0;
        size_t curr_zero = 0;

        for (const char ch : s) {
            switch (ch) {
                case '0':
                    curr_one = 0;
                    curr_zero += 1;
                    longest_zero = std::max(longest_zero, curr_zero);
                    break;
                case '1':
                    curr_zero = 0;
                    curr_one += 1;
                    lonegst_one = std::max(lonegst_one, curr_one);
                    break;
                default:
                    curr_zero = 0;
                    curr_one = 0;
                    break;
            }
        }

        return lonegst_one > longest_zero;
    }
};
