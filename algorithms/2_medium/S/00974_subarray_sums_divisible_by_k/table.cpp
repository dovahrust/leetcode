class Solution {
public:
    static int subarraysDivByK(const vector<int>& nums, const int k) {
        assert(k >= 2 && k <= 10'000 && nums.size() <= 30'000);
        auto freqs = vector<int>(k, 0);
        int sum = 0;
        freqs[0] = 1;

        for (const int num : nums) {
            sum += num;
            freqs[((sum % k) + k) % k] += 1;
        }

        int res = 0;
        for (const int freq : freqs) {
            res += freq * (freq - 1) / 2;
        }

        return res;
    }
};
