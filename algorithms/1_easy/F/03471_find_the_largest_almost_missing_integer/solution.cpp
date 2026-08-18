class Solution {
public:
    static int largestInteger(const vector<int>& nums, const int k) {
        const ptrdiff_t len = std::ssize(nums);

        if (k >= len) {
            return *(std::max_element(nums.cbegin(), nums.cend()));
        }

        if (1 < k) {
            const size_t freq_first = count(nums.cbegin(), nums.cend(), nums[0]);
            const size_t freq_last = count(nums.cbegin(), nums.cend(), nums[len - 1]);

            if (freq_first == 1 && freq_last == 1) {
                return max(nums[0], nums[len - 1]);
            } else if (freq_first == 1) {
                return nums[0];
            } else if (freq_last == 1) {
                return nums[len - 1];
            } else {
                return -1;
            }
        }

        auto freqs = unordered_map<int, int>();

        for (const int num : nums) {
           freqs[num] += 1;
        }

        int max = numeric_limits<int>::min();
        bool has_valid_ans = false;

        for (const auto [num, freq] : freqs) {
            if (freq == 1) {
                max = std::max(max, num);
                has_valid_ans = true;
            }
        }

        if (!has_valid_ans) {
            return -1;
        }

        return max;
    }
};
