class Solution {
public:
    static bool uniformArray(const vector<int>& nums1) {
        assert(!nums1.empty());

        int min = numeric_limits<int>::max();
        bool has_odd = false;

        for (const int num : nums1) {
            min = std::min(min, num);
            if ((num & 1) == 1) {
                has_odd = true;
            }
        }

        if ((min & 1) == 0 && has_odd) {
            return false;
        }

        return true;
    }
};
