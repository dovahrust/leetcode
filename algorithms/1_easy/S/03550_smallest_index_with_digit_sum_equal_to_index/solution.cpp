class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        const size_t len = nums.size();

        for (size_t i = 0; i < len; ++i) {
            int dig_sum = 0;
            int value = nums[i];

            while (value > 0) {
                dig_sum += value % 10;
                value /= 10;
            }
    
            if (dig_sum == static_cast<int>(i)) {
                return static_cast<int>(i);
            }
        }

        return -1;
    }
};
