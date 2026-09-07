int countRotations(const char *restrict s, int k) {
    if (s == NULL || s[0] == '\0' || s[1] == '\0') { return -1; }

    const size_t len = strlen(s);
    int eq = 0;
    int ne = 0;
    for (int i = 1; i < len; i += 1) {
        if (s[i] == s[i - 1]) {
            eq += 1;
        } else {
            ne += 1;
        }
    }
    if (s[len - 1] == s[0]) {
        eq += 1;
    } else {
        ne += 1;
    }

    if (k == eq - 1) {
        return eq;
    }

    if (k == eq) {
        return ne;
    }

    return 0;
}
