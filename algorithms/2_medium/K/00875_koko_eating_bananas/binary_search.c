int minEatingSpeed(const int *restrict piles, const int len, const int h) {
    if (piles == NULL || len <= 0 || h <= 0 || len > h) { return -1; }

    int hi = 0;
    for (int i = 0; i < len; i += 1) { hi = MAX(hi, piles[i]); }
    int lo = 1;

    while (lo <= hi) {
        const int mid = lo + (hi - lo) / 2;

        int total = 0;
        for (int i = 0; i < len; i += 1) {
            total += (piles[i] + mid - 1) / mid;
            if (total > h) {
                break;
            }
        }

        if (total <= h) {
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    return lo;
}
