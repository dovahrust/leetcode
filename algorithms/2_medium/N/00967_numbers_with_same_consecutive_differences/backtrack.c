struct vec {
    int *restrict ptr;
    size_t cap;
    size_t len;
};

static inline bool vec_push(struct vec* vec, const int val) {
    if (vec->cap == vec->len) {
        const size_t new_cap = vec->cap == 0 ? 4 : vec->cap * 2;
        void *new_ptr = realloc(vec->ptr, new_cap * sizeof(*vec->ptr));
        if (new_ptr == NULL) {
            return false;
        }
        vec->ptr = new_ptr;
        vec->cap = new_cap;
    }

    vec->ptr[vec->len] = val;
    vec->len += 1;
    return true;
}

static void dfs(const int n, const int diff, struct vec* res, const int curr) {
    if (n == 0) {
        if (!(vec_push(res, curr))) {
            exit(0);
        }
        return;
    }

    const int last = curr % 10;
    if (last + diff <= 9) {
        dfs(n - 1, diff, res, (curr * 10) + last + diff);
    }

    if (diff != 0 && last - diff >= 0) {
        dfs(n - 1, diff, res, (curr * 10) + last - diff);
    }
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* numsSameConsecDiff(const int n, const int k, int* return_len) {
    assert(n >= 2 && n <= 9 && k >= 0 && k <= 9 && return_len != NULL);
    struct vec res = { .ptr = NULL, .cap = 0, .len = 0 };

    for (int i = 1; i <= 9; i += 1) {
        dfs(n - 1, k, &res, i);
    }

    assert(res.len <= (size_t)INT_MAX);
    *return_len = (int)res.len;
    return res.ptr;
}
