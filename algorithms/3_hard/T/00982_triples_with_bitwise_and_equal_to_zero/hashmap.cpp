class Solution {
public:
    int countTriplets(vector<int>& nums) {
        auto hashmap = unordered_map<int, int>();
        for (const auto n1 : nums) {
            for (const auto n2 : nums) {
                hashmap[(n1 & n2)] += 1;
            }
        }

        int cnt = 0;
        for (const int num : nums) {
            for (const auto [other, freq] : hashmap) {
                if ((num & other) == 0) {
                    cnt += freq;
                }
            }
        }

        return cnt;
    }
};
