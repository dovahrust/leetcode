static void dfs(
    const char* s, const size_t idx,
    uint16_t* vals, size_t* vals_len,
    char*** res, size_t* res_len, size_t* res_cap
) {
    if (s[idx] == '\0') {
        if (*vals_len != 4) {
            return;
        }
        if (*res_cap == *res_len) {
            const size_t new_cap = *res_cap == 0 ? 4 : 2 * (*res_cap);
            *res = realloc(*res, new_cap * sizeof(**res));
            if (*res == NULL) {
                fprintf(stderr, "alloc fail");
                exit(1);
            }
            *res_cap = new_cap;
        }

        char* temp = NULL;
        if (asprintf(&temp, "%i.%i.%i.%i", vals[0], vals[1], vals[2], vals[3]) == -1 ) {
            fprintf(stderr, "alloc fail");
            exit(1);
        }
        (*res)[*res_len] = temp;
        *res_len += 1;
        return;
    }

    const uint16_t dig = (uint16_t)(s[idx] - '0');
    if (*vals_len < 4) {
        vals[*vals_len] = dig;
        *vals_len += 1;
        dfs(s, idx + 1, vals, vals_len, res, res_len, res_cap);
        *vals_len -= 1;
    } 

    if (*vals_len > 0) {
        const uint16_t last = vals[*vals_len - 1];
        if (last != 0 && (last * 10) + dig <= 255) {
            vals[*vals_len - 1] = (last * 10) + dig;
            dfs(s, idx + 1, vals, vals_len, res, res_len, res_cap);
        }
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** restoreIpAddresses(const char* s, int* return_len) {
    if (s == NULL) {
        *return_len = 0;
        return NULL;
    }
    uint16_t vals[4] = { 0 };
    size_t vals_len = 0;
    char** res = NULL;
    size_t res_len = 0;
    size_t res_cap = 0;

    dfs(s, 0, vals, &vals_len, &res, &res_len, &res_cap);

    if (res_len > (size_t)INT_MAX) {
        fprintf(stderr, "logic error");
        exit(1);
    }

    *return_len = (int)res_len;
    return res;
}
