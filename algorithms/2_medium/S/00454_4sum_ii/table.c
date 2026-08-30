#include<threads.h>

#define MAX_LEN 200
#define TABLE_LEN (MAX_LEN * MAX_LEN * 2)

inline static size_t hash_int(const int n) {
    return ((size_t)n << 1) ^ ((size_t)n >> 1);
}

struct cell {
    int stamp;
    int key;
    int val;
};

thread_local static struct cell table[TABLE_LEN];
thread_local static int stamp;

__attribute__((no_sanitize("all")))
inline static void table_inc_or_insert(const int key, const int amount) {
    size_t idx = hash_int(key) % TABLE_LEN;
    while (table[idx].stamp == stamp) {
        if (table[idx].key == key) {
            table[idx].val += amount;
            return;
        }
        idx += 1;
        if (idx == TABLE_LEN) {
            idx = 0;
        }
    }
    table[idx].stamp = stamp;
    table[idx].key = key;
    table[idx].val = amount;
}

__attribute__((no_sanitize("all")))
inline static int table_get_val_or_default_zero(const int key) {
    size_t idx = hash_int(key) % TABLE_LEN;
    while (table[idx].stamp == stamp) {
        if (table[idx].key == key) {
            return table[idx].val;
        }
        idx += 1;
        if (idx == TABLE_LEN) {
            idx = 0;
        }
    }
    return 0;
}

__attribute__((no_sanitize("all")))
int fourSumCount(
    const int *nums1, const int len1,
    const int *nums2, const int len2,
    const int *nums3, const int len3,
    const int *nums4, const int len4
) {
    if (len1 <= 0 || len2 <= 0 || len3 <= 0 || len4 <= 0 ||
        len1 > MAX_LEN || len2 > MAX_LEN || len3 > MAX_LEN || len4 > MAX_LEN ||
        nums1 == NULL || nums2 == NULL || nums3 == NULL || nums4 == NULL
    ) {
        return -1;
    }

    stamp += 1;
    if (stamp == INT_MAX) {
        for (size_t i = 0; i < TABLE_LEN; i += 1) {
            table[i].stamp = 0;
        }
        stamp = 1;
    }

    for (int i = 0; i < len1; i += 1) {
        const int n1 = nums1[i];
        for (int j = 0; j < len2; j += 1) {
            const int sum = n1 + nums2[j];
            table_inc_or_insert(sum, 1);
        }
    }

    int cnt = 0;

    for (int i = 0; i < len3; i += 1) {
        const int n3 = nums3[i];
        for (int j = 0; j < len4; j += 1) {
            const int sum = n3 + nums4[j];
            const int other = -sum;
            cnt += table_get_val_or_default_zero(other);
        }
    }

    return cnt;
}
