#include<threads.h>

#define FREQS_LEN 10
#define MIN_NUM 100
#define MAX_NUM 999
#define TABLE_LEN ((MAX_NUM - MIN_NUM + 1) >> 1)

thread_local static uint8_t table[TABLE_LEN];
thread_local static uint8_t stamp;

static inline void init_table() {
    if (stamp == UINT8_MAX) {
        for (int i = 0; i < TABLE_LEN; i += 1) {
            table[i] = 0;
        }
        stamp = 0;
    }

    stamp += 1;
}

static void dfs(const int curr, uint32_t *freqs) {
    if (curr >= 100) {
        if ((curr & 1) == 1) {
            return;
        }
        table[(curr - MIN_NUM) >> 1] = stamp;
        return;
    }

    for (int i = 0; i < FREQS_LEN; i += 1) {
        if (freqs[i] >= 1) {
            freqs[i] -= 1;
            dfs(curr * 10 + i, freqs);
            freqs[i] += 1;
        }
    }
}

int totalNumbers(const int *restrict digits, const int len) {
    if (digits == NULL || len < 3) { return -1; }

    uint32_t freqs[FREQS_LEN] = { 0 };
    bool has_even = false;
    bool has_non_zero = false;
    for (int i = 0; i < len; i += 1) {
        if (digits[i] < 0 || digits[i] > 9) { return -1; }

        freqs[digits[i]] += 1;
        has_even |= ((digits[i] & 1) == 0);
        has_non_zero |= (digits[i] != 0);
    }

    if (!has_even || !has_non_zero) { return 0; }

    init_table();

    for (int i = 1; i < FREQS_LEN; i += 1) {
        if (freqs[i] >= 1) {
            freqs[i] -= 1;
            dfs(i, freqs);
            freqs[i] += 1;
        }
    }

    int cnt = 0;
    for (int i = 0; i < TABLE_LEN; i += 1) {
        if (table[i] == stamp) {
            cnt += 1;
        }
    }

    return cnt;
}
