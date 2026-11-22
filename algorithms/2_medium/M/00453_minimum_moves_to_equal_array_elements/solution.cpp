class Solution {
public:
    static int minMoves(const vector<int>& nums) {
        const int min = *min_element(nums.cbegin(), nums.cend());
        int cnt = 0;

        for (const auto num : nums) { cnt += num - min; }

        return cnt;
    }
};
