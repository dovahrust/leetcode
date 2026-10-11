typedef ptrdiff_t isize;

char *removeOuterParentheses(char *s) {
    if (s == NULL) { return NULL; }

    isize balance = 0;
    size_t write_idx = 0;

    for (size_t read_idx = 0; s[read_idx] != '\0'; read_idx += 1) {
        const char ch = s[read_idx];

        if (ch == '(') {
            balance += 1;
        } else {
            balance -= 1;
        }

        if ((balance == 1 && ch == '(') || balance == 0) {
            continue;
        }

       s[write_idx] = ch;
       write_idx += 1;
    }

    s[write_idx] = '\0';
    return s;
}
