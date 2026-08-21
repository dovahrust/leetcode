class Solution {
    struct Cmp {
        bool operator()(const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
            return std::get<0>(a) > std::get<0>(b);
        }
    };
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        assert(
            k >= 1 && k <= std::ssize(nums1) * std::ssize(nums2) &&
            nums1.size() > 0 && nums1.size() <= 100'000 &&
            nums2.size() > 0 && nums2.size() <= 100'000
        );

        const int len1 = static_cast<int>(std::ssize(nums1));
        const int len2 = static_cast<int>(std::ssize(nums2));
        auto heap = priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, Cmp>();
        const int heap_len = std::min(k, len1);
        for (int i = 0; i < heap_len; i += 1) {
            heap.push({ nums1[i] + nums2[0], i, 0 });
        }
        auto res = vector<vector<int>>();
        res.reserve(k);

        for (int step = 0; step < k; step += 1) {
            const auto [sum, idx1, idx2] = heap.top();
            heap.pop();
            res.push_back(vector<int>{ nums1[idx1], nums2[idx2] });
            if (idx2 + 1 < len2) {
                heap.push({ nums1[idx1] + nums2[idx2 + 1], idx1, idx2 + 1 });
            }
        }

        return res;
    }
};
