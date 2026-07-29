class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        const size_t len = nums.size();
        assert(limit >= 0);
        auto minq = deque<int>();
        auto maxq = deque<int>();
        size_t lo = 0;
        size_t res = 0;

        for (size_t hi = 0; hi < len; hi += 1) {
            const int num = nums[hi];
            while (!maxq.empty() && maxq.back() < num) {
                maxq.pop_back();
            }
            while (!minq.empty() && minq.back() > num) {
                minq.pop_back();
            }
            maxq.push_back(num);
            minq.push_back(num);

            while (limit < maxq.front() - minq.front()) {
                if (maxq.front() == nums[lo]) {
                    maxq.pop_front();
                }
                if (minq.front() == nums[lo]) {
                    minq.pop_front();
                }
                lo += 1;
            }

            res = std::max(res, hi - lo + 1);
        }

        assert(res <= static_cast<size_t>(numeric_limits<int>::max()));
        return static_cast<int>(res);
    }
};
