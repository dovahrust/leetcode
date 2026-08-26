class Solution {
    static void dfs(const int n, const int diff, vector<int>& res, const int curr) {
        if (n == 0) {
            res.push_back(curr);
            return;
        }

        const int last = curr % 10;
        if (last + diff <= 9) {
            dfs(n - 1, diff, res, (curr * 10) + last + diff);
        }

        if (diff != 0 && last - diff >= 0) {
            dfs(n - 1, diff, res, (curr * 10) + last - diff);
        }
    }

public:
    static vector<int> numsSameConsecDiff(const int n, const int k) {
        assert(n >= 2 && n <= 9 && k >= 0 && k <= 9);
        auto res = vector<int>();

        for (int i = 1; i <= 9; i += 1) {
            dfs(n - 1, k, res, i);
        }

        return res;
    }
};
