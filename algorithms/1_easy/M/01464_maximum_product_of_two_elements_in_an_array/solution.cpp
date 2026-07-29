class Solution {
public:
    static int maxProduct(const vector<int>& nums) {
        assert(std::ssize(nums) >= 2);
        int max1 = numeric_limits<int>::min();
        int max2 = numeric_limits<int>::min();

        for(const int num : nums) {
            if (num >= max1) {
                max2 = max1;
                max1 = num;
            } else if(num >= max2) {
                max2 = num;
            }
        }

        return (max1 - 1) * (max2 - 1);
    }
};
