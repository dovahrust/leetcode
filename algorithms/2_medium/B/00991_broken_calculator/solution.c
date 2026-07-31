int brokenCalc(const int start_value, const int target) {
    int cnt = 0;
    int mul = 1;

    while (start_value * mul < target) {
        mul <<= 1;
        cnt += 1;
    }

    int diff = start_value * mul - target;

    while (diff != 0) {
        cnt += diff / mul;
        diff = diff % mul;
        mul >>= 1;
    }

    return cnt;
}
