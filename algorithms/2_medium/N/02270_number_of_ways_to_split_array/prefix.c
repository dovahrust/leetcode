int waysToSplitArray(const int *restrict nums, const int len) {
    if (len <= 1) { return 0; }

    int64_t suff = 0;
    for (int i = 0; i < len; i+= 1) { suff += nums[i]; }

    int64_t pref = 0;
    int cnt = 0;

     for (int i = 0; i < len - 1; i+= 1) {
        pref += nums[i];
        suff -= nums[i];

        if (pref >= suff) {
            cnt += 1;
        }
    }

    return cnt;
}
