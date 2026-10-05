class Solution {
    static void dfs(string &tmp, vector<string>& res, const int n, const int open_cnt, const int close_cnt) {
        if (open_cnt == n && close_cnt == n) {
            res.push_back(tmp);
            return;
        }

        if (open_cnt < n) {
            tmp.push_back('(');
            dfs(tmp, res, n, open_cnt + 1, close_cnt);
            tmp.pop_back();
        }

        if (close_cnt < open_cnt) {
            tmp.push_back(')');
            dfs(tmp, res, n, open_cnt, close_cnt + 1);
            tmp.pop_back();
        }
    }

public:
    static vector<string> generateParenthesis(int n) {
        auto tmp = string();
        auto res = vector<string>();
        dfs(tmp, res, n, 0, 0);
        return res;
    }
};
