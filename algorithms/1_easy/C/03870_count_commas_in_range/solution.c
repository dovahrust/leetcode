int countCommas(const int n_int) {
    if (n_int < 1000) { return 0; }

    long long n = n_int;
    long long base = 999;
    long long cnt = 0;

    while (base <= n) {
        cnt += (n - base);
        base = base * 1000 + 999;
    }

    return (int)cnt;
}
