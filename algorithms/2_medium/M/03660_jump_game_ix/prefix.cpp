typedef ptrdiff_t isize;

class Solution {
public:
    static vector<int> maxValue(const vector<int>& nums) {
        if (nums.empty()) { return vector<int>(); }
        const isize len = std::ssize(nums);
        auto prefix = vector<int>(len, 0);
        prefix[0] = nums[0];
        for (isize i = 1; i < len; i += 1) {
            prefix[i] = std::max(nums[i], prefix[i - 1]);
        }
        int curr_min = numeric_limits<int>::max();
        int curr_max = 0;
        for (isize i = len - 1; i >= 0; i -= 1) {
            if (prefix[i] > curr_min) {
                prefix[i] = curr_max;
                curr_min = std::min(curr_min, nums[i]);
            } else {
                curr_max = prefix[i];
                curr_min = nums[i];
            }
        }

        return prefix;
    }
};
