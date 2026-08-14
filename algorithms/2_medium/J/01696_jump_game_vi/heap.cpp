class Solution {
public:
    static int maxResult(const vector<int>& nums, const int k) {
        assert(nums.size() >= 1 && nums.size() <= 10e5 && k >= 1);

        if (nums.size() == 1 || k == 1) {
            return reduce(nums.cbegin(), nums.cend(), 0);
        }

        const int32_t len = static_cast<int32_t>(std::ssize(nums));
        auto heap = priority_queue<pair<int, int32_t>>();
        heap.push({nums[0], 0});
        int dp_i = nums[0];

        for (int32_t i = 1; i < len; i += 1) {
            const int32_t start = std::max(i - k, 0);

            while (heap.top().second < start) {
                heap.pop();
            }

            dp_i = nums[i] + heap.top().first;
            heap.push({dp_i, i});
        }

        return dp_i;
    }
};
