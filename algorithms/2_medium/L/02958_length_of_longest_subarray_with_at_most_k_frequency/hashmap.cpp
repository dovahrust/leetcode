class Solution {
public:
    static int maxSubarrayLength(const vector<int>& nums, const int k) {
        assert(k >= 1 && k <= std::ssize(nums) && nums.size() <= 100'000);
        const size_t len = nums.size();
        auto freqs = unordered_map<int, int>();
        size_t lo = 0;
        size_t max = 0;
        for (size_t hi = 0; hi < len; hi += 1) {
            freqs[nums[hi]] += 1;
            while (freqs[nums[hi]] > k) {
                freqs[nums[lo]] -= 1;
                lo += 1;
            }
            max = std::max(max, hi - lo + 1);
        }

        return static_cast<int>(max);
    }
};
