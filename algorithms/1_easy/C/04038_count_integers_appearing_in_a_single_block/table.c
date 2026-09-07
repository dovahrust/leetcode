#include<threads.h>

#define MAX_NUM 100
#define TABLE_LEN (MAX_NUM + 1)
#define EMPTY 0
#define VALID 1
#define INVALID 2

thread_local static int8_t table[TABLE_LEN];

int countSpecialIntegers(const int *restrict nums, int len) {
    if (len == 0 || nums == NULL) { return 0; }
    if (nums[0] <= 0 || nums[0] > MAX_NUM) { return -1; }

    for (size_t i = 0; i < TABLE_LEN; i += 1) { table[i] = EMPTY; }

    table[nums[0]] = VALID;

    for (int i = 1; i < len; i += 1) {
        if (nums[i] == nums[i - 1]) { continue; }
        if (nums[i] <= 0 || nums[i] > MAX_NUM) { return -1; }

        if (table[nums[i]] == EMPTY) {
            table[nums[i]] = VALID;
        } else {
            table[nums[i]] = INVALID;
        }
    }

    int cnt = 0;
    for (size_t i = 0; i < TABLE_LEN; i += 1) {
        if (table[i] == VALID) {
            cnt += 1;
        }
    }

    return cnt;
}
