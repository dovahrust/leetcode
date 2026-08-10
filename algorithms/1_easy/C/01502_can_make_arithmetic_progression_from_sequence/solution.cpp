class Solution {
public:
    static bool canMakeArithmeticProgression(vector<int>& arr) {
        if (arr.size() <= 2) { return true; }
        sort(arr.begin(), arr.end());
        const int diff = arr[1] - arr[0];

        for (auto it = arr.cbegin() + 2; it != arr.cend(); it += 1) {
            if (*it - *(it - 1) != diff) {
                return false;
            }
        }

        return true;
    }
};
