inline static size_t custom_tok(const char *restrict preorder, size_t idx) {
    while (preorder[idx] != '\0' && preorder[idx] != ',') {
        idx += 1;
    }
    return idx;
}

bool isValidSerialization(const char *preorder) {
    if (preorder == NULL || preorder[0] == '\0') { exit(1); }

    size_t balance = 1;
    size_t begin = 0;

    while (true) {
        if (balance == 0) {
            return false;
        }

        const size_t end = custom_tok(preorder, begin);

        if (preorder[begin] == '#') {
            balance -= 1;
        } else {
            balance += 1;
        }

        if (preorder[end] == '\0') {
            break;
        }
        begin = end + 1;
    }

    return balance == 0;
}
