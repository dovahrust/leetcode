class Solution {
public:
    static int missingMultiple(const vector<int>& nums, const int k) {
        assert(k > 0);
        auto hashset = unordered_set<int>();

        for (const int num : nums) {
            if (num % k == 0) {
                hashset.insert(num);
            }
        }

        int curr = k;

        while (hashset.find(curr) != hashset.end()) {
            curr += k;
        }

        return curr;
    }
};
