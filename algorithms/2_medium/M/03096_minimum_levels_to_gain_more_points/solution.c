int minimumLevels(const int *restrict possible, const int len) {
    assert(len > 1);

    int pref = 0;
    int suff = 0;

    for (int i = 0; i < len; i += 1) {
        if (possible[i] == 1) {
            suff += 1;
        } else {
            suff -= 1;
        }
    }

    for (int i = 0; i < len - 1; i += 1) {
        if (possible[i] == 1) {
            pref += 1;
            suff -= 1;
        } else {
            pref -= 1;
            suff += 1;
        }

        if (pref > suff) {
            return i + 1;
        }
    }

    return -1;
}
