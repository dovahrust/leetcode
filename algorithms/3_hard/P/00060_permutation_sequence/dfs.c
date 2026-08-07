static void dfs(const uint8_t n, int *k, char *res, size_t *res_len, const uint16_t seen) {
    if (*k == 0) {
        return;
    }

    if (seen == (1u << n) - 1u) {
        *k -= 1;
        return;
    }

    for (uint8_t i = 1; i <= n; i += 1) {
        const uint16_t mask = 1u << (i - 1);
        if ((mask & seen) == 0) {
            res[*res_len] = (char)i + '0';
            *res_len += 1;
            dfs(n, k, res, res_len, seen | mask);
            if (*k == 0) {
                return;
            }
            *res_len -= 1;
        }
    }
}

char* getPermutation(const int n, int k) {
    if (n > 9 || n < 1 || k < 1) {
        fprintf(stderr, "invalid input");
        exit(1);
    }
    char* res = malloc((size_t)(n + 1));
    if (res == NULL) {
        fprintf(stderr, "alloc fail");
        exit(1);
    }
    size_t res_len = 0;
    res[n] = '\0';
    uint16_t seen = 0;
    dfs((uint8_t)n, &k, res, &res_len, seen);
    return res;
}
