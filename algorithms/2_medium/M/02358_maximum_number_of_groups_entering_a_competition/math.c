int maximumGroups(const int *grades, int len) {
    const int p = (int)sqrt(len * 2);

    if (p * (p + 1) / 2 <= len) {
        return p;
    } else {
        return p - 1;
    }
}
