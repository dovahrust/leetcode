typedef ptrdiff_t isize;

int minOperations(const char* s) {
    if (s == NULL) { return -2; }
    const isize len = (isize)strlen(s);

    bool is_sorted = true;
    for (isize i = 1; i < len; i += 1) {
        if (s[i - 1] > s[i]) {
            is_sorted = false;
            break;
        }
    }
    if (is_sorted) {
        return 0;
    }
    if (len == 2) {
        return -1;
    }

    unsigned char min = 255;
    isize min_freq = 0;
    unsigned char max = 0;
    isize max_freq = 0;

    for (isize i = 0; i < len; i += 1) {
        const unsigned char ch = (const unsigned char)s[i];
        if (ch < min) {
            min = ch;
            min_freq = 1;
        } else if (ch == min) {
            min_freq += 1;
        }

        if (ch > max) {
            max = ch;
            max_freq = 1;
        } else if (ch == max) {
            max_freq += 1;
        }
    }

    if (s[0] == min || s[len - 1] == max) {
        return 1;
    }

    if (max_freq == 1 && min_freq == 1 && s[0] == max && s[len - 1] == min ) {
        return 3;
    }

    return 2;
}
