typedef ptrdiff_t isize;

int minInsertions(char* s) {
    isize balance = 0;
    isize needs = 0;

    for (size_t i = 0; s[i] != '\0'; i += 1) {
        switch (s[i]) {
            case '(':
                if ((balance & 1) == 1) {
                    needs += 1;
                    balance += 1;
                } else {
                    balance += 2;
                }
                break;
            case ')':
                if (balance == 0) {
                    balance = 1;
                    needs += 1;
                } else {
                    balance -= 1;
                }
                break;
            default:
                return -1;
        }
    }

    return (int)(needs + balance);
}
