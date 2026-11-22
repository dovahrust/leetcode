class Solution {
public:
    static int maxSelectedElements(vector<int>& nums) {
        ranges::sort(nums);
        auto hashmap = unordered_map<int, int>();

        for (const int num : nums) {
            const auto by_inc = hashmap.find(num);
            hashmap[num + 1] = 1 + (by_inc == hashmap.end() ? 0 : by_inc->second);

            const auto by_keep = hashmap.find(num - 1);
            hashmap[num] = 1 + (by_keep == hashmap.end() ? 0 : by_keep->second);
        }

        int res = numeric_limits<int>::min();
        for (const auto it : hashmap) {
            res = std::max(res, it.second);
        }
        return res;
    }
};
