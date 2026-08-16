class Solution {
public:
    static bool mergeTriplets(const vector<vector<int>>& triplets, const vector<int>& target) {
        bool seen_0 = false;
        bool seen_1 = false;
        bool seen_2 = false;

        for (const auto& t : triplets) {
            if (t[0] <= target[0] && t[1] <= target[1] && t[2] <= target[2]) {
                seen_0 |= (t[0] == target[0]);
                seen_1 |= (t[1] == target[1]);
                seen_2 |= (t[2] == target[2]);
            }

            if (seen_0 && seen_1 && seen_2) {
                return true;
            }
        }

        return false;
    }
};
