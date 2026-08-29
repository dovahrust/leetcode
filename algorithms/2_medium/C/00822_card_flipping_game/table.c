#include<threads.h>

#define MAX_NUM 2000
#define MIN_NUM 1
#define TABLE_LEN (MAX_NUM - MIN_NUM + 1)
#define VALID 1
#define INVALID 2

struct pair {
    uint8_t stamp;
    uint8_t state;
};

thread_local static uint8_t stamp;
thread_local static struct pair states[TABLE_LEN];

int flipgame(const int *restrict fronts, const int fronts_len, const int *restrict backs, const int backs_len) {
    if (fronts_len != backs_len || fronts_len <= 0 || fronts == NULL || backs == NULL) {
        return -1;
    }

    stamp += 1;
    if (stamp == UINT8_MAX) {
        for (int i = 0; i < TABLE_LEN; i += 1) {
            states[i].stamp = 0;
        }
        stamp = 1;
    }

    const int len = fronts_len;
    for (int i = 0; i < len; i += 1) {
        const int f = fronts[i];
        const int b = backs[i];
        if (f < MIN_NUM || b < MIN_NUM || f > MAX_NUM || b > MAX_NUM) {
            return -1;
        }

        if (f != b) {
            if (states[f - MIN_NUM].stamp != stamp) {
                states[f - MIN_NUM].stamp = stamp;
                states[f - MIN_NUM].state = VALID;
            }

            if (states[b - MIN_NUM].stamp != stamp) {
                states[b - MIN_NUM].stamp = stamp;
                states[b - MIN_NUM].state = VALID;
            }
        } else {
            states[f - MIN_NUM].stamp = stamp;
            states[f - MIN_NUM].state = INVALID;
        }
    }

    for (int i = 0; i < TABLE_LEN; i += 1) {
        if (states[i].stamp == stamp && states[i].state == VALID) {
            return i + MIN_NUM;
        }
    }

    return 0;
}
