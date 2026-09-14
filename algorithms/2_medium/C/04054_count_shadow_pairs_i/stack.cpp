class Solution {
public:
    static long long shadowPairs(const vector<int>& nums) {
        auto stack = vector<pair<int, size_t>>();
        stack.reserve(nums.size());
        size_t cnt = 0;

        for (const int num : nums) {
            while (!stack.empty() && stack.back().first > num) {
                stack.pop_back();
            }

            if (!stack.empty()) {
                const auto [top, prev_num_cnt] = stack.back();
                if (top == num) {
                    cnt += prev_num_cnt;
                    stack.push_back({ num, prev_num_cnt });
                } else {
                    cnt += stack.size();
                    stack.push_back({ num, stack.size() });
                }
            } else {
                stack.push_back({ num, 0 });
            }
        }

        return static_cast<long long>(cnt);
    }
};
