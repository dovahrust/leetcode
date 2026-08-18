class Solution {
public:
    static string kthLargestNumber(vector<string>& nums, const int k) {
        const ptrdiff_t len = std::ssize(nums);
        assert(k >= 1 && k <= len);
        ranges::sort(nums, [](const string& a, const string& b) {
            if (a.size() != b.size()) {
                return a.size() < b.size();
            } else {
                return a < b;
            }
        });

        return nums[len - k];
    }
};
