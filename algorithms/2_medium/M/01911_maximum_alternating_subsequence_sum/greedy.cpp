class Solution {
public:
    static long long maxAlternatingSum(const vector<int>& nums) {
        int prev_num = 0;
        long long curr_sum = 0;

        for (const int num : nums) {
            if (num > prev_num) {
                curr_sum += num - prev_num;
            }
            prev_num = num;
        }

        return curr_sum;
    }
};
