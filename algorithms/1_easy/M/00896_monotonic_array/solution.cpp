class Solution {
public:
    static bool isMonotonic(const vector<int>& nums) noexcept {
        if (nums.size() <= 1) {
            return true;
        }

        const size_t len = nums.size();
        int state = 0;

        for (size_t i = 1; i < len; i += 1) {
            if (nums[i] > nums[i - 1]) {
                if (state == -1) {
                    return false;
                }
                state = 1;
            } else if (nums[i] < nums[i - 1]) {
                if (state == 1) {
                    return false;
                }
                state = -1;
            }
        }

        return true;
    }
};
