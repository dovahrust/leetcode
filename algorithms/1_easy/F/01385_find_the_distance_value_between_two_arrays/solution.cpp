class Solution {
public:
    static int findTheDistanceValue(const vector<int>& arr1, vector<int>& arr2, const int d) {
        ranges::sort(arr2);
        int cnt = 0;
        const size_t len2 = arr2.size();

        for (const int num1 : arr1) {
            const size_t pos = lower_bound(arr2.cbegin(), arr2.cend(), num1) - arr2.cbegin();

            if (pos < len2 && std::abs(num1 - arr2[pos]) <= d) {  continue; }

            if (pos != 0 && std::abs(num1 - arr2[pos - 1]) <= d) {  continue; }

            cnt += 1;
        }

        return cnt;
    }
};
