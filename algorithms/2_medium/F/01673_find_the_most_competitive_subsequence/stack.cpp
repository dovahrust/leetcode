class Solution {
public:
    static vector<int> mostCompetitive(const vector<int>& nums, const int k) {
        assert(k >= 1 && k <= std::ssize(nums));
        const ptrdiff_t len = std::ssize(nums);

        auto stack = vector<int>();
        stack.reserve(k);

        for (ptrdiff_t i = 0; i < len; i += 1) {
            const int num = nums[i];
            const ptrdiff_t remains = len - i;

            while (!stack.empty() && remains + std::ssize(stack) > k && stack.back() > num) {
                stack.pop_back();
            }

            if (std::ssize(stack) < k) {
                stack.push_back(num);
            }
        }

        return stack;
    }
};
