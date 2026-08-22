class Solution {
public:
    static int numSubarrayProductLessThanK(const vector<int>& nums, const int k) {
        assert(k >= 0 && k <= 1'000'000);

        if (k <= 1) { return 0; }

        const size_t len = nums.size();
        size_t lo = 0;
        int prod = 1;
        size_t cnt = 0;

        for (size_t hi = 0; hi < len; hi += 1) {
            assert(nums[hi] >= 1 && nums[hi] <= 1000);
            prod *= nums[hi];

            while (prod >= k) {
                prod /= nums[lo];
                lo += 1;
            }

            cnt += (hi + 1) - lo;
        }

        return static_cast<int>(cnt);
    }
};
