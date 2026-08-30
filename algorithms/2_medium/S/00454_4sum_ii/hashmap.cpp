class Solution {
public:
    static int fourSumCount(
        const vector<int>& nums1,
        const vector<int>& nums2,
        const vector<int>& nums3,
        const vector<int>& nums4
    ) {
        auto hashmap = unordered_map<int, int>();
        int cnt = 0;

        for (const int n1 : nums1) {
            for (const int n2 : nums2) {
                hashmap[n1 + n2] += 1;
            }
        }

        for (const int n3 : nums3) {
            for (const int n4 : nums4) {
                const int sum = n3 + n4;
                const int other = -sum;

                const auto it  = hashmap.find(other);
                if (it != hashmap.end()) {
                    cnt += it->second;
                }
            }
        }

        return cnt;
    }
};
