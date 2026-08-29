class Solution {
public:
    static int minEatingSpeed(const vector<int>& piles, const int h) {
        int hi = *std::max_element(piles.cbegin(), piles.cend());
        int lo = 1;

        while (lo <= hi) {
            const int mid = lo + (hi - lo) / 2;

            int total = 0;
            for (const int p : piles) {
                total += (p + mid - 1) / mid;
                if (total > h) {
                    break;
                }
            }

            if (total <= h) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return lo;
    }
};
