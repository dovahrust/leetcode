typedef ptrdiff_t isize;

class Solution {
public:
    static int findLength(const vector<int>& nums1, const vector<int>& nums2) {
        assert(nums1.size() <= 1000 && nums2.size() <= 1000);
        if (nums1.size() == 0 || nums2.size() == 0) { return 0; }

        const auto n1 = nums1.size() >= nums2.size() ?
                        span<const int>(nums1.data(), nums1.size()) :
                        span<const int>(nums2.data(), nums2.size());
        const auto n2 = nums1.size() >= nums2.size() ?
                        span<const int>(nums2.data(), nums2.size()) :
                        span<const int>(nums1.data(), nums1.size());

        const isize len1 = std::ssize(n1);
        const isize len2 = std::ssize(n2);

        auto buff = vector<int16_t>(2 * (len2 + 1), 0);
        auto curr = span<int16_t>(&buff[0], len2 + 1);
        auto next = span<int16_t>(&buff[len2 + 1], len2 + 1);
        int16_t res = 0;

        for (isize i = len1 - 1; i >= 0; i -= 1) {
            for (isize j = len2 - 1; j >= 0; j -= 1) {
                if (n1[i] == n2[j]) {
                    const int16_t val = 1 + next[j + 1];
                    curr[j] = val;
                    res = std::max(res, val);
                }
            }
            std::swap(curr, next);
            for (auto& c : curr) {
                c = 0;
            }
        }

        return res;
    }
};
