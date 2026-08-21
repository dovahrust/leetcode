class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        auto hashmap = unordered_map<int, int>();
        hashmap[0] = 1;
        int sum = 0;
        int cnt = 0;

        for (const int num : nums) {
            sum += num;

            auto it = hashmap.find(sum - k);
            if (it != hashmap.end()) {
                cnt += it->second;
            }

            hashmap[sum] += 1;
        }

        return cnt;
    }
};
