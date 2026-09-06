bool doesAliceWin(const char *restrict s) {
    if (s == NULL || s[0] == '\0') { goto err; }

    for (size_t i = 0; s[i] != '\0'; i += 1) {
        switch (s[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                return true;
            default:
                if (s[i] > 'z' || s[i] < 'a') { goto err; }
                break;
        }
    }

    return false;

err:
    fprintf(stderr, "invalid input");
    exit(1);
}
