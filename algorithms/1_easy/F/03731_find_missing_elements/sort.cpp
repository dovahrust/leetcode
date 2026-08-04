class Solution {
public:
    static vector<int> findMissingElements(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        auto res = vector<int>();

        for (auto it = nums.cbegin() + 1; it != nums.cend(); it += 1) {
            if (*it != *(it - 1)) {
                for (int k = *(it - 1) + 1; k < *it; k += 1) {
                    res.push_back(k);
                }
            }
        }

        return res;
    }
};
