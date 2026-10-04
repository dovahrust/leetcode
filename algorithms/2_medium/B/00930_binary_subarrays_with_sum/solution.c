int numSubarraysWithSum(const int *restrict nums, const int len, const int goal) {
    int res = 0;
    int sum = 0;
    int lo = 0;
    int mid = 0;

    for (int hi = 0; hi < len; hi += 1) {
        sum += nums[hi];

        if (sum > goal) {
            sum -= nums[mid];
            lo = mid + 1;
            mid = lo;
        }

        if (lo <= hi && sum == goal) {
            while (mid < hi && nums[mid] == 0) {
                mid += 1;
            }
            res += mid + 1 - lo;
        }
    }

    return res;
}
