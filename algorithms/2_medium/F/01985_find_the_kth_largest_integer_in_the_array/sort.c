struct pair {
    char *restrict s;
    size_t len;
};

static int cmp(const void *restrict a_ptr, const void *restrict b_ptr) {
    const struct pair *restrict a = a_ptr;
    const struct pair *restrict b = b_ptr;

    if (a->len != b->len) {
        return (a->len > b->len) - (a->len < b->len);
    } else {
        return strcmp(a->s, b->s);
    }
}

char* kthLargestNumber(char *restrict *restrict nums, const int len, int k) {
    if (nums == NULL || len <= 0 || k > len) { goto invalid_input; }

    struct pair* arr = malloc((size_t)len * sizeof(*arr));
    if (arr == NULL) { goto alloc_fail; }

    for (int i = 0; i < len; i += 1) {
        if (nums[i] == NULL) {
            goto invalid_input_free_arr;
        }

        arr[i] = (struct pair){ .s = nums[i], .len = strlen(nums[i]) };
    }

    qsort(arr, (size_t)len, sizeof(*arr), cmp);
    char* res = arr[len - k].s;
    free(arr);
    return res;

alloc_fail:
    return NULL;

invalid_input_free_arr:
    free(arr);
invalid_input:
    return NULL;
}
