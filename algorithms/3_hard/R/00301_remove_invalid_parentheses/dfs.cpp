static size_t calc_valid_pairs_cnt(const string& s) {
    size_t pair_cnt = 0;
    size_t open_cnt = 0;

    for (const char ch : s) {
        switch (ch) {
            case '(':
                open_cnt += 1;
                break;
            case ')':
                if (open_cnt > 0) {
                    open_cnt -= 1;
                    pair_cnt += 1;
                }
                break;
            default:
                break;
        }
    }

    return pair_cnt;
}

static void dfs(
    const string& s, const size_t idx,
    const size_t valid_pairs,
    const size_t open_use,
    const size_t close_use,
    string& stack, 
    unordered_set<string>& res
) {
    if (open_use > valid_pairs) { return; }

    if (idx == s.size()) {
        if (open_use == valid_pairs && close_use == valid_pairs) {
            res.insert(stack);
        }

        return;
    }

    switch (s[idx]) {
        case '(':
            stack.push_back('(');
            dfs(s, idx + 1, valid_pairs, open_use + 1, close_use, stack, res);
            stack.pop_back();

            dfs(s, idx + 1, valid_pairs, open_use, close_use, stack, res);
            break;
        case ')':
            if (close_use < open_use) {
                stack.push_back(')');
                dfs(s, idx + 1, valid_pairs, open_use, close_use + 1, stack, res);
                stack.pop_back();
            }

            dfs(s, idx + 1, valid_pairs, open_use, close_use, stack, res);
            break;
        default:
            stack.push_back(s[idx]);
            dfs(s, idx + 1, valid_pairs, open_use, close_use, stack, res);
            stack.pop_back();
    }
}

class Solution {
public:
    static vector<string> removeInvalidParentheses(const string& s) {
        const size_t valid_pairs = calc_valid_pairs_cnt(s);
        auto res = unordered_set<string>();
        auto stack = string();
        stack.reserve(s.size());

        dfs(s, 0, valid_pairs, 0, 0, stack, res);

        return vector<string>(res.begin(), res.end());
    }
};
