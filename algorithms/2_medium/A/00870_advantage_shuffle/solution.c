struct pair {
    int val;
    int idx;
};

__attribute__((no_sanitize("all")))
static int cmp_int_inc(const void *restrict a_ptr, const void *restrict b_ptr) {
    const int a = *(int*)a_ptr;
    const int b = *(int*)b_ptr;
    return (a > b) - (a < b);
}

__attribute__((no_sanitize("all")))
static int cmp_pair_dec(const void *restrict a_ptr, const void *restrict b_ptr) {
    struct pair a = *(struct pair*)a_ptr;
    struct pair b = *(struct pair*)b_ptr;
    return (a.val < b.val) - (a.val > b.val);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
__attribute__((no_sanitize("all")))
int* advantageCount(
    int *restrict nums1, const int len1,
    const int *restrict nums2, const int len2,
    int *restrict return_len
) {
    const int len = len1;
    if (len != len2 || len < 1 || len > 10e5 || nums1 == NULL || nums2 == NULL || return_len == NULL) {
        goto invalid_input;
    }

    struct pair *restrict combo2 = malloc((size_t)len * sizeof(*combo2));
    if (combo2 == NULL) {
        goto alloc_fail;
    }
    for (int i = 0; i < len; i += 1) {
        combo2[i] = (struct pair){ .val = nums2[i], .idx = i };
    }

    int *restrict res = malloc((size_t)len * sizeof(*res));
    if (res == NULL) {
        goto alloc_fail_free_combo;
    }

    qsort(nums1, (size_t)len, sizeof(*nums1), cmp_int_inc);
    qsort(combo2, (size_t)len, sizeof(*combo2), cmp_pair_dec);

    int begin = 0;
    int end = len;

    for (int i = 0; i < len; i += 1) {
        const int num = combo2[i].val; 
        const int idx = combo2[i].idx;

        if (num < nums1[end - 1]) {
            res[idx] = nums1[end - 1];
            end -= 1;
        } else {
            res[idx] = nums1[begin];
            begin += 1;
        }
    }

    free(combo2);
    *return_len = len;
    return res;

invalid_input:
    fprintf(stderr, "invalid input");
    *return_len = -1;
    return NULL;

alloc_fail_free_combo:
    free(combo2);
alloc_fail:
    fprintf(stderr, "alloc fail\n");
    *return_len = -1;
    return NULL;
}
