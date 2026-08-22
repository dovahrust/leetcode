class Solution {
public:
    static vector<int> resultArray(const vector<int>& nums) {
        if (nums.size() <= 2) { return nums; }

        const size_t len = nums.size();
        auto res = vector<int>(len);
        size_t hi = len - 1;
        res[hi] = nums[1];
        size_t lo = 0;
        res[lo] = nums[0];

        for (size_t i = 2; i < len; i += 1) {
            if (res[hi] > res[lo]) {
                hi -= 1;
                res[hi] = nums[i];
            } else {
                lo += 1;
                res[lo] = nums[i];
            }
        }

        std::reverse(res.begin() + hi, res.end());

        return res;
    }
};
