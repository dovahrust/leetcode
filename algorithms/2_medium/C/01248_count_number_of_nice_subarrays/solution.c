int numberOfSubarrays(const int *restrict nums, const int len, const int k) {
    int odd_cnt = 0;
    int lo = 0;
    int mid = 0;
    int res = 0;

    for (int hi = 0; hi < len; hi += 1) {
        if ((nums[hi] & 1) == 1) { odd_cnt += 1; }

        if (odd_cnt > k) {
            odd_cnt = k;
            mid += 1;
            lo = mid;
        }

        if (odd_cnt == k) {
            while ((nums[mid] & 1) == 0) {
                mid += 1;
            }
            res += mid - lo + 1;
        }
    }

    return res;
}
