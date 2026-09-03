typedef ptrdiff_t isize;

class Solution {
public:
    static int minSwaps(const vector<int>& nums) {
        const isize len = std::ssize(nums);
        isize ones = 0;

        for (isize i = 0; i < len; i += 1) {
            assert(nums[i] == 0 || nums[i] == 1);
            ones += nums[i];
        }

        if (ones <= 1 || (len - ones) <= 1) {
            return 0;
        }

        isize freq_window = 0;
        for (isize i = len - ones; i < len; i += 1) { freq_window += nums[i]; }

        isize need = ones - freq_window;

        for (isize i = 0; i < len - 1; i += 1) {
            freq_window += nums[i];
            freq_window -= nums[(len - ones + i) % len];
            need = std::min(need, ones - freq_window);
        }

        return static_cast<int>(need);
    }
};
