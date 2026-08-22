class Solution {
public:
    static long long maxScore(const vector<int>& nums1, const vector<int>& nums2, const int k_int) {
        assert(nums1.size() == nums2.size() && k_int >= 1 && k_int <= std::ssize(nums1));

        const size_t len = nums1.size();
        const size_t k = static_cast<size_t>(k_int);
        auto combo = vector<pair<int, int>>(len);
        for (size_t i = 0; i < len; i += 1) {
            combo[i] = { nums2[i], nums1[i] };
        }
        ranges::sort(combo, [](const auto& a, const auto& b) {
            return a.first > b.first;
        });
        auto heap = priority_queue<int, vector<int>, std::greater<int>>();
        int64_t sum = 0;
        int64_t res = numeric_limits<int64_t>::min();

        for (size_t i = 0; i < len; i += 1) {
            heap.push(combo[i].second);
            sum += combo[i].second;
            if (heap.size() > k) {
                sum -= heap.top();
                heap.pop();
            }
            if (i >= k - 1) {
                const int64_t min_n2 = combo[i].first;
                res = std::max(res, min_n2 * sum);
            }
        }

        return res;
    }
};
