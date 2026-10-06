int minAddToMakeValid(char* s) {
    size_t res = 0;
    size_t open_cnt = 0;

    for (size_t i = 0; s[i] != '\0'; i += 1) {
        if (s[i] == '(') {
            open_cnt += 1;
        } else {
            if (open_cnt > 0 ) {
                open_cnt -= 1;
            } else {
                res += 1;
            }
        }
    }

    return (int)(res + open_cnt);
}
