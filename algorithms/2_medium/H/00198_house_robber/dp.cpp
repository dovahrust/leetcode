class Solution {
public:
    static int rob(const vector<int>& nums) {
        int prev = 0;
        int prev_prev = 0;

        for (const int num : nums) {
            const int curr = num + prev_prev;
            prev_prev = std::max(prev_prev, prev);
            prev = curr;
        }

        return std::max(prev, prev_prev);
    }
};
