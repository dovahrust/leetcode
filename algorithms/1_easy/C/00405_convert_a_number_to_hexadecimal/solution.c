char* toHex(const int num) {
    if (num == 0) {
        return strdup("0");
    }

    unsigned int u_num = (unsigned int)num;
    char* res= malloc(9 * sizeof(*res));
    assert(res != NULL);
    size_t res_len = 0;

    while (u_num > 0) {
        const unsigned int curr_dig = u_num % 16;
        u_num /= 16;

        if (curr_dig > 9) {
            res[res_len] = (char)(curr_dig - 10 + 'a');
        } else {
            res[res_len] = (char)(curr_dig + '0');
        }
        res_len += 1;
    }

    res[res_len] = '\0';
    size_t lo = 0;
    size_t hi = res_len - 1;
    while (lo < hi) {
        const char temp = res[lo];
        res[lo] = res[hi];
        res[hi] = temp;
        lo += 1;
        hi -= 1;
    }

    return res;
}
