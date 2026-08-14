typedef ptrdiff_t isize;

class Solution {
public:
    static vector<int> advantageCount(vector<int>& nums1, const vector<int>& nums2) {
        const isize len = std::ssize(nums1);
        assert(len == nums2.size() && len >= 1 && len <= 100'000);

        auto combo2 = vector<pair<int, int>>();
        combo2.reserve(len);
        for (isize i = 0; i < len; i += 1) {
            combo2.push_back(make_pair(nums2[i], static_cast<int>(i)));
        }

        auto res = vector<int>(len, 0);

        ranges::sort(nums1);
        ranges::sort(combo2);

        isize begin = 0;
        isize end = len;

        for (auto it = combo2.crbegin(); it != combo2.crend(); it += 1) {
            const auto [num, idx] = *it;

            if (num < nums1[end - 1]) {
                res[idx] = nums1[end - 1];
                end -= 1;
            } else {
                res[idx] = nums1[begin];
                begin += 1;
            }
        }

        return res;
    }
};
