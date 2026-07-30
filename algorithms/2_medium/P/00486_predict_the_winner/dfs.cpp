typedef ptrdiff_t isize;

class Solution {
    static bool dfs(
        const vector<int>& nums,
        const isize lo,
        const isize hi,
        const bool p1_turn,
        const int balance
    ) {
        if (lo > hi) {
            return balance >= 0;
        }

        if (p1_turn) {
            return dfs(nums, lo + 1, hi, !p1_turn, balance + nums[lo]) ||
                   dfs(nums, lo, hi - 1, !p1_turn, balance + nums[hi]);
        } else {
            return dfs(nums, lo + 1, hi, !p1_turn, balance - nums[lo]) &&
                   dfs(nums, lo, hi - 1, !p1_turn, balance - nums[hi]);
        }
    }
public:
    static bool predictTheWinner(const vector<int>& nums) {
        assert(std::ssize(nums) <= 20);
        return dfs(nums, 0, std::ssize(nums) - 1, true, 0);
    }
};
