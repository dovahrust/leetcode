class Solution {
    static int dfs(
        const span<const int> n1, const size_t n1_idx,
        const span<const int> n2, const size_t n2_idx,
        span<int> memo
    ) {
        const size_t n1_len = n1.size();
        const size_t n2_len = n2.size();
        if (n1_idx == n1_len || n2_idx == n2_len) {
            return 0;
        }
        const size_t memo_idx = n1_idx * n2_len + n2_idx;
        if (memo[memo_idx] != -1) {
            return memo[memo_idx];
        }

        int res = 0;
        if (n1[n1_idx] == n2[n2_idx]) {
            res = 1 + dfs(n1, n1_idx + 1, n2, n2_idx + 1, memo);
        }
        res = std::max(res, dfs(n1, n1_idx + 1, n2, n2_idx, memo));
        res = std::max(res, dfs(n1, n1_idx, n2, n2_idx + 1, memo));

        memo[memo_idx] = res;
        return res;
    }

public:
    static int maxUncrossedLines(const vector<int>& nums1, const vector<int>& nums2) {
        const size_t len1 = nums1.size();
        const size_t len2 = nums2.size();
        assert(len1 >= 1 && len1 <= 500 && len2 >= 1 && len2 <= 500);

        auto memo = vector<int>(len1 * len2, -1);

        return dfs(nums1, 0, nums2, 0, memo);
    }
};
