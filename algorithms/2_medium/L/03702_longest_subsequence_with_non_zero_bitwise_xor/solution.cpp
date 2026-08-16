class Solution {
public:
    static int longestSubsequence(const vector<int>& nums) {
        const size_t len = nums.size();
        int xor_nums = 0;
        size_t zeros = 0;

        for (const int num : nums) {
            xor_nums ^= num;
            if (num == 0) {
                zeros += 1;
            }
        }

        if (zeros == len) {
            return 0;
        }

        if (xor_nums != 0) {
            return static_cast<int>(len);
        }

        return static_cast<int>(len) - 1;
    }
};
