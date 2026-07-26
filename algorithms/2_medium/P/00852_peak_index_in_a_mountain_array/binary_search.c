int peakIndexInMountainArray(const int* arr, const int len)
{
    assert(len >= 3 && arr != NULL);
    int hi = len - 1;
    int lo = 0;

    while (lo <= hi) {
        const int mid = lo + (hi - lo) / 2;
        assert(mid != len - 1 && "invalid input");
        if (arr[mid + 1] > arr[mid]) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    return lo;
}
