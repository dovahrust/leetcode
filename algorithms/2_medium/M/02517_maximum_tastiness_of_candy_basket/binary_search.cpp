static inline bool is_ok(const span<const int> prices, int k, const int mid) {
    k -= 1;
    int curr = prices[0];
    const ptrdiff_t len = std::ssize(prices);

    for (ptrdiff_t i = 1; i < len; i += 1) {
        if (prices[i] - curr >= mid) {
            k -= 1;
            curr = prices[i];

            if (k == 0) {
                return true;
            }
        }
    }

    return false;
}

class Solution {
public:
    static int maximumTastiness(vector<int>& prices, int k) {
        if (k < 2 || k > std::ssize(prices) || std::ssize(prices) > 100000) {
            cerr << "invalid input";
            return -1;
        }

        int lo = 0;
        int hi = INT_MAX;
        std::sort(prices.begin(), prices.end());

        while (lo <= hi) {
            const int mid = lo + (hi - lo) / 2;
            if (is_ok(prices, k, mid)) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return hi;
    }
};
