static inline int max_int(const int a, const int b) {
    return a > b ? a : b;
}

static inline int min_int(const int a, const int b) {
    return a < b ? a : b;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* maxValue(const int* nums, const int len, int* return_len) {
    if (len <= 0 || nums == NULL || return_len == NULL) {
        fprintf(stderr, "invalid input");
        exit(1);
    }

    int* prefix = malloc((size_t)len * sizeof(*prefix));
    if (prefix == NULL) {
        fprintf(stderr, "alloc fail");
        exit(1);
    }
    *return_len = len;
    prefix[0] = nums[0];
    for (int i = 1; i < len; i += 1) {
        prefix[i] = max_int(nums[i], prefix[i - 1]);
    }

    int curr_min = INT_MAX;
    int curr_max = 0;
    for (int i = len - 1; i >= 0; i -= 1) {
        if (prefix[i] > curr_min) {
            prefix[i] = curr_max;
            curr_min = min_int(curr_min, nums[i]);
        } else {
            curr_max = prefix[i];
            curr_min = nums[i];
        }
    }

    return prefix;
}
