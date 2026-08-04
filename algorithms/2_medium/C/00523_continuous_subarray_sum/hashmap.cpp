class Solution {
public:
    static bool checkSubarraySum(const vector<int>& nums, const int k) {
        assert(k >= 1 && std::ssize(nums) <= 100'000);
        const int32_t len = static_cast<int32_t>(std::ssize(nums));
        auto hashmap = unordered_map<int32_t, int32_t>();
        int32_t prefix = 0;

        hashmap[0] = -1;

        for (int32_t i = 0; i < len; i += 1) {
            prefix += nums[i];
            const int32_t pref_mod_k = prefix % k;
            const auto it = hashmap.find(pref_mod_k);

            if (it != hashmap.end()) {
                if (i - it->second >= 2) {
                    return true;
                }
            } else {
                hashmap[pref_mod_k] = i;
            }
        }

        return false;
    }
};
