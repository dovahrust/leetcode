int minDeletion(const int *restrict nums, const int len) {
    if (len <= 1) { return len; }

    int cnt = 1;
    int lo = 0;

    for (int hi = 1; hi < len; hi += 1) {
        if (((cnt - 1) & 1) == 0) {
            if (nums[lo] != nums[hi]) {
                lo = hi;
                cnt += 1;
            }
        } else {
            lo = hi;
            cnt += 1;
        }
    }

    if ((cnt & 1) == 1) {
        cnt -= 1;
    }

    const int needs = len - cnt;
    return needs;
}
