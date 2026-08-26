class Solution {
public:
    static int minIncrementForUnique(vector<int>& nums) {
        ranges::sort(nums);
        int expect = numeric_limits<int>::min();
        int needs = 0;
        for (const int num : nums) {
            expect = std::max(expect, num);
            needs += expect - num;
            expect += 1;
        }

        return needs;
    }
};
