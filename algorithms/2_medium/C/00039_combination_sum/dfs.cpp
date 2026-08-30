class Solution {
    static void dfs(
        const vector<int>& candidates,
        const size_t idx,
        const int target,
        vector<vector<int>>& res,
        vector<int>& tmp
    ) {
        if (target == 0) {
            res.push_back(tmp);
            return;
        }

        if (target < 0 || idx >= candidates.size()) {
            return;
        }

        tmp.push_back(candidates[idx]);
        dfs(candidates, idx, target - candidates[idx], res, tmp);
        tmp.pop_back();

        dfs(candidates, idx + 1, target, res, tmp);
    }

public:
    static vector<vector<int>> combinationSum(const vector<int>& candidates, const int target) {
        auto res = vector<vector<int>>();
        auto tmp = vector<int>();

        dfs(candidates, 0, target, res, tmp);

        return res;
    }
};
