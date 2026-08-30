struct vec {
    char **ptr;
    size_t len;
    size_t cap;
    bool err;
};

inline static const char *get_letters(const char ch) {
    switch (ch) {
        case '2': return "abc";
        case '3': return "def";
        case '4': return "ghi";
        case '5': return "jkl";
        case '6': return "mno";
        case '7': return "pqrs";
        case '8': return "tuv";
        case '9': return "wxyz";
        default: return NULL;
    }
}

static void backtrack(
    const char *restrict digits,
    const size_t idx,
    char *restrict tmp,
    struct vec *res
) {
    if (res->err) { return; }

    if (digits[idx] == '\0') {
        if (res->len == res->cap) {
            const size_t new_cap = res->cap == 0 ? 4 : res->cap * 2;
            char **ptr = realloc(res->ptr, new_cap * sizeof(*(res->ptr)));
            if (ptr == NULL) {
                res->err = true;
                return;
            }
            res->ptr = ptr;
            res->cap = new_cap;
        }
        char *tmp_dup = strdup(tmp);
        if (tmp_dup == NULL) {
            res->err = true;
            return;
        }
        res->ptr[res->len] = tmp_dup;
        res->len += 1;
        return;
    }

    const char *restrict letters = get_letters(digits[idx]);
    if (letters == NULL) {
        res->err = true;
        return;
    }

    for (size_t i = 0; letters[i] != '\0'; i += 1) {
        tmp[idx] = letters[i];
        backtrack(digits, idx + 1, tmp, res);
        tmp[idx] = ' ';
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(const char *restrict digits, int *restrict return_len) {
    if (return_len == NULL) { return NULL; }
    if (digits == NULL || digits[0] == '\0') { goto err; }

    const size_t len = strlen(digits);
    struct vec res = { .ptr = NULL, .cap = 0, .len = 0, .err = false };
    char *restrict tmp = malloc((len + 1) * sizeof(*tmp));
    if (tmp == NULL) { goto err; }
    tmp[len] = '\0';

    backtrack(digits, 0, tmp, &res);
    free(tmp);

    if (res.err || res.len > (size_t)INT_MAX) {
        for (size_t i = 0; i < res.len; i += 1) {
            free(res.ptr[i]);
        }
        free(res.ptr);
        goto err;
    }

    *return_len = (int)res.len;
    return res.ptr;

err:
    *return_len = 0;
    return NULL;
}
