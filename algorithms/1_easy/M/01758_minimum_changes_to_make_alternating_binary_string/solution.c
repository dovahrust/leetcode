int minOperations(const char *restrict s) {
    size_t zero_first = 0;
    size_t one_first = 0;

    for (size_t i = 0; s[i] != '\0'; i += 1) {
        if ((i & 1) == 0) {
            switch (s[i]) {
                case '0': 
                    one_first += 1;
                    break;
                case '1':
                    zero_first += 1;
                    break;
                default:
                    return -1;
            }
        } else {
            switch (s[i]) {
                case '0': 
                    zero_first += 1;
                    break;
                case '1':
                    one_first += 1;
                    break;
                default:
                    return -1;
            }
        }
    }

    return (int)MIN(zero_first, one_first);
}
