typedef ptrdiff_t isize;

class Solution {
public:
    static vector<int> pancakeSort(vector<int>& arr) {
        const isize len = std::ssize(arr);
        auto res = vector<int>();

        for (isize i = len - 1; i >= 0; i -= 1) {
            isize idx_max = 0;
            for (isize j = 0; j <= i; j += 1) {
                if (arr[j] >= arr[idx_max]) {
                    idx_max = j;
                }
            }

            if (idx_max != i) {
                res.push_back(idx_max + 1);
                std::reverse(arr.begin(), arr.begin() + idx_max + 1);

                res.push_back(i + 1);
                std::reverse(arr.begin(), arr.begin() + i + 1);
            }
        }

        return res;
    }
};
