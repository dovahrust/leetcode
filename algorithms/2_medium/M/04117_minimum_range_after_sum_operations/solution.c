int minRange(const int a, const int b, const int c) {
    const int uc =  MAX(a , MAX(b, c)) - MIN(a, MIN(b, c));
    const int ac = b + c - MIN(b, c);
    const int bc = a + c - MIN(a, c);
    const int cc = a + b - MIN(a, b);

    return MIN(MIN(uc, ac), MIN(bc, cc));
}
