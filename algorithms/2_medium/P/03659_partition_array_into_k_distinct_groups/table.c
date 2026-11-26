#include<threads.h>

#define MAX_NUM 100000

thread_local static int freqs[MAX_NUM + 1];

bool partitionArray(const int *restrict nums, const int len, const int k) {

    assert(len > 0 && k > 0 && nums != NULL);

    if (len % k != 0) { return false; }

    int max = 0;
    for (int i = 0; i < len; i += 1) {
        assert(nums[i] > 0 && nums[i] <= MAX_NUM);
        max = MAX(max, nums[i]);
    }

    for (int i = 0; i <= max; i += 1) { freqs[i] = 0; }

    const int max_allow = len / k;

    for (int i = 0; i < len; i += 1) {
        int *entry = &freqs[nums[i]];
        *entry += 1;

        if (*entry > max_allow) { return false; }
    }

    return true;
}
