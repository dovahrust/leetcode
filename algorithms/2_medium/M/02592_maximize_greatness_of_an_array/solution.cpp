class Solution {
public:
    static int maximizeGreatness(vector<int>& nums) {
        ranges::sort(nums);

        const size_t len = nums.size();
        size_t lo = 0;

        for (size_t hi = 0; hi < len; hi += 1) {
            if (nums[hi] > nums[lo]) {
                lo += 1;
            }
        }

        return static_cast<size_t>(lo);
    }
};
