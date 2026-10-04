typedef ptrdiff_t isize;

bool checkValidString(const char *restrict s) {
    isize points = 0;
    isize balance = 0;
    isize len = (isize)strlen(s);

    for (isize i = 0; i < len; i += 1) {
        const char ch = s[i];
        if (ch == ')') {
            balance -= 1;

            if (balance < 0) {
                if (points <= 0) { return false; }

                points -= 1;
                balance += 1;
            }
        } else if (ch == '(') {
            balance += 1;
        } else {
            points += 1;
        }
    }

    balance = 0;
    points = 0;

    for (isize i = len - 1; i >= 0; i -= 1) {
        const char ch = s[i];
        if (ch == '(') {
            balance -= 1;

            if (balance < 0) {
                if (points <= 0) { return false; }

                points -= 1;
                balance += 1;
            }
        } else if (ch == ')') {
            balance += 1;
        } else {
            points += 1;
        }
    }

    return true;
}
