bool checkString(char* s) {
    bool seen_b = false;
    for (size_t i = 0; s[i] != '\0'; i += 1) {
        if (s[i] == 'b') {
            seen_b = true;
        } else if (seen_b) {
            return false;
        }
    }

    return true;
}
