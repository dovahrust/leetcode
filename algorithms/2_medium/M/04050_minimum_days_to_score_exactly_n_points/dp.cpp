class Solution {
public:
    int minDays(int n) {
        assert(n >= 1 && n <= 100'000);
        constexpr int reset_cost = 1;
        int width = 1;
        int width_cost = 1;
        auto dp = vector<int>(n + 1, numeric_limits<int>::max());
        dp[0] = 0;

        while (width <= n) {
            dp[width] = width_cost;

            for (int i = width + 1; i <= n; i += 1) {
                dp[i] = std::min(dp[i], dp[i - width] + width_cost + reset_cost);
            }

            width_cost += 1;
            width += width_cost;
        }

        return dp[n];
    }
};
