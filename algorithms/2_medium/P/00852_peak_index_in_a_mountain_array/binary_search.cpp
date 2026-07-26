typedef ptrdiff_t isize;

class Solution {
public:
    int peakIndexInMountainArray(const vector<int>& arr) {
        const isize len = std::ssize(arr);
        assert(len >= 3);
        isize hi = len - 1;
        isize lo = 0;

        while (lo <= hi) {
            const isize mid = lo + (hi - lo) / 2;
            assert(mid != len - 1 && "invalid input");
            if (arr[mid + 1] > arr[mid]) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return static_cast<int>(lo);
    }
};
