int minimumMoves(const char *restrict s) {
    if (s == NULL) { return 0; }

    const size_t len = strlen(s);
    size_t idx = 0;
    size_t cnt = 0;

    while (idx < len) {
        switch (s[idx]) {
            case 'X':
                idx += 3;
                cnt += 1;
                break;
            case 'O':
                idx += 1;
                break;
            default:
                return -1;
        }
    }

    return (int)cnt;
}
