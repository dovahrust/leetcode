char* shiftingLetters(char *restrict s, int *restrict shifts, const int len) {
    if (len <= 0) { return s; }

    shifts[len - 1] %= 26;
    for (int i = len - 2; i >= 0; i -= 1) {
        shifts[i] = (shifts[i] + shifts[i + 1]) % 26;
    }

    for (int i = 0; i < len; i += 1) {
        const int shift = shifts[i];
        const int v = (s[i] - 'a' + shift) % 26;
        s[i] = (char)(v + 'a');
    }

    return s;
}
