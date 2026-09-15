int pivotIndex(const int *restrict nums, int len) {
    int suff = 0;
    for (int i = 0; i < len; i += 1) { suff += nums[i]; }

    int pref = 0;
    int cnt = 0;

     for (int i = 0; i < len; i+= 1) {
        suff -= nums[i];

        if (pref == suff) {
            return i;
        }

        pref += nums[i];
    }

    return -1;
}
