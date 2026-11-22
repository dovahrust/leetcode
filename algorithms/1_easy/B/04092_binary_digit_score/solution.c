int calculateScore(const int a, const int b) {
    const int s1 = __builtin_popcount(a);
    const int s2 = __builtin_popcount(b);

    return s1 >= s2 ? s1 * s2 : s2 / s1;
}
