__attribute__((no_sanitize("all")))
static inline int max_int(const int a, const int b) {
    return a > b ? a : b;
}

struct entity {
    bool is_fill;
    int key;
    int freq;
};

__attribute__((no_sanitize("all")))
static inline void update_freqs(
    struct entity *restrict freqs, const size_t freqs_len,
    const int key,
    const int amount
) {
    size_t idx = (size_t)key % freqs_len;
    while (freqs[idx].is_fill) {
        if (freqs[idx].key == key) {
            break;
        }
        idx += 1;
        if (idx == freqs_len) {
            idx = 0;
        }
    }
    freqs[idx].key = key;
    freqs[idx].is_fill = true;
    freqs[idx].freq += amount;
}

__attribute__((no_sanitize("all")))
static inline int get_freq(
    struct entity *restrict freqs, const size_t freqs_len,
    const int key
) {
    size_t idx = (size_t)key % freqs_len;
    while (freqs[idx].is_fill) {
        if (freqs[idx].key == key) {
            break;
        }
        idx += 1;
        if (idx == freqs_len) {
            idx = 0;
        }
    }
    return freqs[idx].freq;
}

__attribute__((no_sanitize("all")))
int maxSubarrayLength(const int *restrict nums, const int len, const int k) {
    if (!(k >= 1 && k <= len && len <= 100000 && nums != NULL)) { goto input_err; }

    const size_t freqs_len = (size_t)(2 * len);
    struct entity *restrict freqs = calloc(freqs_len, sizeof(*freqs));
    if (freqs == NULL) { goto alloc_fail; }

    int lo = 0;
    int max = 0;
    for (int hi = 0; hi < len; hi += 1) {
        update_freqs(freqs, freqs_len, nums[hi], 1);
        while (get_freq(freqs, freqs_len, nums[hi]) > k) {
            update_freqs(freqs, freqs_len, nums[lo], -1);
            lo += 1;
        }
        max = max_int(max, hi - lo + 1);
    }

/* cleanup: */
    free(freqs);
    return max;

alloc_fail:
    fprintf(stderr, "alloc fail");
    return -1;

input_err:
    fprintf(stderr, "invalid input");
    return -1;
}
