class Solution {
public:
    static int minCostClimbingStairs(const vector<int>& cost) {
        int prev = 0;
        int prev_prev = 0;

        for (const int c : cost) {
            const int curr = c + std::min(prev, prev_prev);
            prev_prev = prev;
            prev = curr;
        }

        return std::min(prev, prev_prev);
    }
};
