class Solution {
public:
    static int sumOfBeauties(const vector<int>& nums) {
        if (nums.size() <= 2) { return 0; }

        const ptrdiff_t len = std::ssize(nums);
        auto min_right = vector<int>(len);
        min_right[len - 1] = nums[len - 1];
        for (ptrdiff_t i = len - 2; i >= 0; i -= 1) {
            min_right[i] = std::min(nums[i], min_right[i + 1]);
        }

        int res = 0;
        int max_left = nums[0];

        for (ptrdiff_t i = 1; i < len -1; i += 1) {
            if (max_left < nums[i] && nums[i] < min_right[i + 1]) {
                res += 2;
            } else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1]) {
                res += 1;
            }

            max_left = std::max(max_left, nums[i]);
        }

        return res;
    }
};
