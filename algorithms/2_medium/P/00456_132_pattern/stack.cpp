class Solution {
public:
    static bool find132pattern(const vector<int>& nums) {
        auto stack = vector<int>();
        stack.reserve(nums.size());
        int third = numeric_limits<int>::min();

        for (auto it = nums.crbegin(); it != nums.crend(); it += 1) {
            const int num = *it;
            if (num < third) {
                return true;
            }

            while (!stack.empty() && num > stack.back()) {
                third = std::max(third, stack.back());
                stack.pop_back();
            }

            stack.push_back(num);
        }

        return false;
    }
};
