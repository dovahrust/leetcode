class Solution {
public:
    static bool canThreePartsEqualSum(const vector<int>& arr) {
        const int sum = reduce(arr.cbegin(), arr.cend(), 0);
        if ((sum % 3) != 0) {
            return false;
        }

        const int target = sum / 3;
        int cnt = 0;
        int curr_sum = 0;
        for (const int a : arr) {
            curr_sum += a;
            if (curr_sum == target) {
                cnt += 1;
                if (cnt == 3) {
                    return true;
                }
                curr_sum = 0;
            }
        }

        return false;
    }
};
