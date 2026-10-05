int minRotations(const char *restrict s) {
    int prev = 0;
    int res = 0;

    for (size_t i = 0; s[i] != '\0'; i += 1) {
        const int curr = s[i] - '0';
        const int diff = ABS(prev - curr);
        res += MIN(diff, 10 - diff);
        prev = curr;
    }

    return res;
}
