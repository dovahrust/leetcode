static inline int max_int(const int a, const int b) {
    return a > b ? a : b;
}

struct cell {
    int prefix;
    int suffix;
};

int longestSubarray(const int* nums, const int len) {
    assert(len >= 1 && len <= 100000 && nums != NULL);
    if (len <= 2) { return len; }

    struct cell* buff = malloc((size_t)len * sizeof(*buff));
    assert(buff != NULL);

    int prefix_cnt = 0;
    int prev_val = 0;
    for (int i = 0; i < len; i += 1) {
        const int num = nums[i];
        if (prev_val <= num) {
            prefix_cnt += 1;
        } else {
            prefix_cnt = 1;
        }
        prev_val = num;
        buff[i].prefix = prefix_cnt;
    }

    int suffix_cnt = 0;
    int next_val = 0;
    for (int i = len - 1; i >= 0; i -= 1) {
        const int num = nums[i];
        if (num <= next_val) {
            suffix_cnt += 1;
        } else {
            suffix_cnt = 1;
        }
        next_val = num;
        buff[i].suffix = suffix_cnt;
    }

    int res = 0;
    for (int i = 1; i + 1 < len; i += 1) {
        if (nums[i - 1] <= nums[i + 1]) {
            const int pref = buff[i - 1].prefix;
            const int suff = buff[i + 1].suffix;
            res = max_int(res, 1 + pref + suff);
        } else {
            res = max_int(res, max_int(1 + buff[i].suffix, 1 + buff[i].prefix));
        }
    }

/* cleanup: */
    free(buff);
    return res;
}
