class Solution {
public:
    int scoreOfParentheses(const string_view s) {
        auto stack = std::stack<int>();
        int score = 0;

        for (const char ch : s) {
            if (ch == '(') {
                stack.push(0);
            } else if (ch == ')') {
                assert(!stack.empty() && "invalid input");
                const int curr = std::max(stack.top(), 1);
                stack.pop();
                if (stack.empty()) {
                    score += curr;
                } else {
                    stack.top() += curr * 2;
                }
            } else {
                assert(false && "invalid input");
            }
        }

        return score;
    }
};
