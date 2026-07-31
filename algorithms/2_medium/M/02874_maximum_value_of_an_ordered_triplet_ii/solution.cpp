class Solution {
public:
    static long long maximumTripletValue(const vector<int>& nums) {
        const size_t len = nums.size();
        if (len < 3) {
            cerr << "invalid input";
            exit(1);
        }

        int diff = nums[0] - nums[1];
        int max = std::max(nums[0], nums[1]);
        int64_t res = 0;

        for (int i = 2; i < len; i += 1) {
            res = std::max(res, static_cast<int64_t>(diff) * nums[i]);
            diff = std::max(diff, max - nums[i]);
            max = std::max(max, nums[i]);
        }

        return res;
    }
};
