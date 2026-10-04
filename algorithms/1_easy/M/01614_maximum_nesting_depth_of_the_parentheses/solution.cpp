class Solution {
public:
    static int maxDepth(const string& s) {
        int max_depth = 0;
        int curr_depth = 0;

        for (const char ch: s) {
            if (ch == '(') {
                curr_depth += 1;
                max_depth = std::max(max_depth, curr_depth);
            } else if (ch == ')') {
                curr_depth -= 1;
            }
        }

        return max_depth;
    }
};
