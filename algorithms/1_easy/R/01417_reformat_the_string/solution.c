typedef ptrdiff_t isize;

static void fix(
    const char *restrict s, const isize len,
    char *restrict res,
    isize start_dig,
    isize start_alph
) {
    for (isize i = 0; i < len; i += 1) {
        if (s[i] >= '0' && s[i] <= '9') {
            res[start_dig] = s[i];
            start_dig += 2;
        } else {
            res[start_alph] = s[i];
            start_alph += 2;
        }
    }
}

char* reformat(const char *restrict s) {
    if (s == NULL) { return s; }

    const isize len = (isize)strlen(s);

    isize cnt_dig = 0;
    isize cnt_alph = 0;

    for (isize i = 0; i < len; i += 1) {
        if (s[i] >= '0' && s[i] <= '9') {
            cnt_dig += 1;
        } else {
            cnt_alph += 1;
        }
    }

    if (ABS(cnt_dig - cnt_alph) > 1) {
        char *res = strdup("");
        assert(res != NULL);
        return res;
    }

    char *res = malloc(((size_t)len + 1) * sizeof(*res));
    assert(res != NULL);
    res[len] = '\0';

    if (cnt_dig > cnt_alph) {
        fix(s, len, res, 0, 1);
    } else {
        fix(s, len, res, 1, 0);
    }

    return res;
}
