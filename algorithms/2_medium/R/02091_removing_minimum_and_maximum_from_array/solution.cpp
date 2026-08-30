class Solution {
public:
    static int minimumDeletions(const vector<int>& nums) {
        if (nums.size() <= 2) { return static_cast<int>(nums.size()); }

        const size_t len = nums.size();
        int max = nums[0];
        size_t max_idx = 0;
        int min = nums[0];
        size_t min_idx = 0;

        for (size_t i = 1; i < len; i += 1) {
            const int num = nums[i];

            if (num > max) {
                max = num;
                max_idx = i;
            }

            if (num < min) {
                min = num;
                min_idx = i;
            }
        }

        const size_t r = std::max(max_idx, min_idx);
        const size_t l = std::min(max_idx, min_idx);

        const size_t from_r = len - r;
        const size_t from_l = l + 1;
        const size_t from_mid = r - l;

        const size_t res = std::min(
            from_l + from_r,
            std::min(from_l + from_mid, from_mid + from_r)
        );

        return static_cast<int>(res);
    }
};
