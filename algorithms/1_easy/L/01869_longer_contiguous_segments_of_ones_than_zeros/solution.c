bool checkZeroOnes(const char *restrict s) {
    if (s == NULL) { return false; }

    size_t lonegst_one = 0;
    size_t longest_zero = 0;
    size_t curr_one = 0;
    size_t curr_zero = 0;

    for (size_t i = 0; s[i] != '\0'; i += 1) {
        switch (s[i]) {
            case '0':
                curr_one = 0;
                curr_zero += 1;
                longest_zero = MAX(longest_zero, curr_zero);
                break;
            case '1':
                curr_zero = 0;
                curr_one += 1;
                lonegst_one = MAX(lonegst_one, curr_one);
                break;
            default:
                curr_zero = 0;
                curr_one = 0;
                break;
        }
    }

    return lonegst_one > longest_zero;
}
