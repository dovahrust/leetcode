class Solution {
public:
    static int minMoves2(vector<int>& nums) {
        ranges::sort(nums);
        const size_t len = nums.size();
        const int median = nums[len / 2];
        int cost = 0;

        for (const int num : nums) { cost += std::abs(num - median); }

        return cost;
    }
};
