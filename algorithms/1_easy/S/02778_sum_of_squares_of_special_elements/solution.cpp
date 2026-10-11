class Solution {
public:
    static int sumOfSquares(const vector<int>& nums) {
        int res = 0;
        const size_t len = nums.size();
        const size_t sqrt_len = static_cast<size_t>(sqrt(len));
        for (size_t i = 1; i <= sqrt_len; i += 1) {
            if (len % i == 0) {
                int other_idx = len / i;
                res += std::pow(nums[i - 1], 2);
                if (other_idx != i) {
                    res += std::pow(nums[other_idx - 1], 2);
                }
            }
        }

        return res;
    }
};
