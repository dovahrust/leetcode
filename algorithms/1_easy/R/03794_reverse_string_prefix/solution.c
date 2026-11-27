char *reversePrefix(char *restrict s, const int k) {
    int i = 0;
    int j = k - 1;

    while (i < j) {
        const char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i += 1;
        j -= 1;
    }

    return s;
}
