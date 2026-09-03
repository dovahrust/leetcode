typedef ptrdiff_t isize;

inline static bool is_ok_forward(const char *restrict s, const char *restrict l, const isize len) {
    isize balance = 0;

    for (isize i = 0; i < len; i += 1) {
        if (l[i] == '1' && s[i] == ')') {
            balance -= 1;
        } else {
            balance += 1;
        }

        if (balance < 0) {
            return false;
        }
    }

    return true;
}

inline static bool is_ok_backward(const char *restrict s, const char *restrict l, const isize len) {
    isize balance = 0;

    for (isize i = len - 1; i >= 0; i -= 1) {
        if (l[i] == '1' && s[i] == '(') {
            balance -= 1;
        } else {
            balance += 1;
        }

        if (balance < 0) {
            return false;
        }
    }

    return true;
}

bool canBeValid(const char *restrict s, const char *restrict locked) {
    const isize len = (isize)strlen(s);

    if ((len & 1) == 1) { return false; }

    return is_ok_forward(s, locked, len) && is_ok_backward(s, locked, len);
}
