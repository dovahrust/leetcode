typedef ptrdiff_t isize;

inline static unsigned char rev_bits(unsigned char ch) {
    unsigned char rev_ch = 0;

    for (int i = 0; i < 8; i += 1) {
        rev_ch <<= 1;
        rev_ch |= (ch & 1);
        ch >>= 1;
    }

    return rev_ch;
}

bool isPalindromic(const char *restrict s) {
    if (s == NULL || s[0] == '\0') { return true; }

    const isize len = (isize)strlen(s);
    isize hi = len - 1;
    isize lo = 0;

    while (lo <= hi) {
        if (rev_bits((unsigned char)s[lo]) != (unsigned char)s[hi]) {
            return false;
        }
        lo += 1;
        hi -= 1;
    }

    return true;
}
