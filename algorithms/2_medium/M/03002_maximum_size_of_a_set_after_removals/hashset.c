struct entity {
    bool is_fill;
    int val;
};

struct hashset {
    size_t len;
    struct entity *restrict ptr;
};

__attribute__((no_sanitize("all")))
static struct hashset hashset_init(const size_t len) {
    struct entity* ptr = calloc(len, sizeof(*ptr));
    if (ptr == NULL) {
        fprintf(stderr, "alloc fail");
        exit(1);
    }
    return (struct hashset){ .ptr = ptr, .len = len };
}

__attribute__((no_sanitize("all")))
static void hashset_insert(struct hashset set, const int val) {
    size_t idx = (size_t)val % set.len;

    #pragma GCC unroll 4
    while (set.ptr[idx].is_fill) {
        if (set.ptr[idx].val == val) {
            return;
        }
        idx += 1;
        if (idx == set.len) {
            idx = 0;
        }
    }

    set.ptr[idx].is_fill = true;
    set.ptr[idx].val = val;
}

__attribute__((no_sanitize("all")))
static bool hashset_contains(struct hashset set, const int val) {
    size_t idx = (size_t)val % set.len;

    #pragma GCC unroll 4
    while (set.ptr[idx].is_fill) {
        if (set.ptr[idx].val == val) {
            return true;
        }
        idx += 1;
        if (idx == set.len) {
            idx = 0;
        }
    }

    return false;
}


__attribute__((no_sanitize("all")))
int maximumSetSize(
    const int* nums1, const int len1,
    const int* nums2, const int len2
) {
    if (len1 != len2 || len1 <= 0 || (len1 & 1) != 0 || len1 > 20000|| nums1 == NULL || nums2 == NULL) {
        fprintf(stderr, "invalid input");
        goto err;
    }
    const int len = len1;
    const int half = len / 2;
    struct hashset set1 = hashset_init((size_t)(len * 2));
    struct hashset set2 = hashset_init((size_t)(len * 2));

    #pragma GCC unroll 8
    for (int i = 0; i < len; i += 1) {
        hashset_insert(set1, nums1[i]);
        hashset_insert(set2, nums2[i]);
    }

    int cnt1 = 0;
    #pragma GCC unroll 4
    for (size_t i = 0; i < set1.len; i += 1) {
        if (set1.ptr[i].is_fill == false) {
            continue;
        }
        const int num = set1.ptr[i].val;
        if (!hashset_contains(set2, num)) {
            cnt1 += 1;
            if (cnt1 == half) {
                break;
            }
        }
    }

    int cnt2 = 0;
    #pragma GCC unroll 4
    for (size_t i = 0; i < set2.len; i += 1) {
        if (set2.ptr[i].is_fill == false) {
            continue;
        }
        const int num = set2.ptr[i].val;
        if (!hashset_contains(set1, num)) {
            cnt2 += 1;
            if (cnt2 == half) {
                break;
            }
        }
    }

    int cnt = cnt1 + cnt2;
    if (cnt < len) {
        #pragma GCC unroll 4
        for (size_t i = 0; i < set1.len; i += 1) {
            if (set1.ptr[i].is_fill == false) {
                continue;
            }
            const int num = set1.ptr[i].val;
            if (hashset_contains(set2, num)) {
                cnt += 1;
                if (cnt == len) {
                    break;
                }
            }
        }
    }

/* cleanup: */
    free(set1.ptr);
    free(set2.ptr);
    return cnt;

err:
    exit(1);
}
