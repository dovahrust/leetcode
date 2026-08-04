class Solution {
public:
    static vector<int> findMissingElements(const vector<int>& nums) {
        const auto set = std::unordered_set<int>(nums.begin(), nums.end());
        const int min = *std::min_element(nums.begin(), nums.end());
        const int max = *std::max_element(nums.begin(), nums.end());
        const int64_t width = static_cast<int64_t>(max) - static_cast<int64_t>(min) + 1;
        const size_t res_len = static_cast<size_t>(width) - set.size();
        auto res = vector<int>();
        res.reserve(res_len);

        for (int val = min; val != max; val += 1) {
            if (!set.contains(val)) {
                res.push_back(val);
            }
        }

        return res;
    }
};
