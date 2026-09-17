int findMiddleIndex(const int *restrict nums, const int len) {
    int suff = 0;
    for (int i = 0; i < len; i += 1) { suff += nums[i]; }
    int pref = 0;;

    for (int i = 0; i < len; i += 1) {
        suff -= nums[i];

        if (suff == pref) {
            return i;
        }

        pref += nums[i];
    }

    return -1;
}
