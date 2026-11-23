class Solution {
public:
    static long long minCost(const vector<int>& nums) {
        const size_t len = nums.size();
        size_t i = 0;
        int64_t cost = numeric_limits<int64_t>::max();

        while (i < len) {
            size_t j = i;
            while (j + 1 < len && nums[j + 1] == nums[i]) { j += 1; }

            const int64_t cost_pref = static_cast<int64_t>(i) * nums[i];
            const int64_t cost_suff = static_cast<int64_t>(len - j - 1) * nums[i];

            if (j != 0 && i != len - 1) { cost = std::min(cost, cost_pref + cost_suff); }

            i = j + 1;
        }

        return cost;
    }
};
