typedef ptrdiff_t isize;

int countValidPrefixes(const char *restrict s) {
    size_t cnt = 0;
    isize balance = 0;
    for (const char *it = s; *it != '\0'; it += 1) {
        switch (*it) {
            case '0':
                balance -= 1;
                break;
            case '1':
                balance += 1;
                break;
            default:
                return -1;
        }

        if (ABS(balance) <= 1) { cnt += 1; }
    }

    return (int)cnt;
}
