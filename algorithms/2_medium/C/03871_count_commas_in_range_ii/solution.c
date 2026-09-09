long long countCommas(const long long n) {
    assert(n >= 1 && n <= 1000000000000000);

    if (n < 1000) { return 0; }

    long long base = 999;
    long long cnt = 0;

    while (base <= n) {
        cnt += (n - base);
        base = base * 1000 + 999;
    }

    return cnt;
}
