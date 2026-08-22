/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include<threads.h>

#define MAX_ALLOWED_NUM 10000

thread_local static uint8_t table[MAX_ALLOWED_NUM + 1];
thread_local static uint8_t stamp = 0;

int numComponents(struct ListNode *restrict head, const int *restrict nums, const int len) {
    if (stamp == UINT8_MAX) {
        stamp = 0;
        for (size_t i = 0; i <= MAX_ALLOWED_NUM; i += 1) {
            table[i] = 0;
        }
    }
    stamp += 1;
    for (int i = 0; i < len; i += 1) {
        if (nums[i] < 0 || nums[i] > MAX_ALLOWED_NUM) {
            return -1;
        }
        table[nums[i]] = stamp;
    }

    bool is_prev_valid = false;
    int cnt = 0;
    struct ListNode *restrict curr = head;

    while (curr != NULL) {
        const int val = curr->val;
        curr = curr->next;

        if (val < 0 || val > MAX_ALLOWED_NUM) {
            return -1;
        }

        if (table[val] == stamp) {
            cnt += is_prev_valid ? 0 : 1;
            is_prev_valid = true;
        } else {
            is_prev_valid = false;
        }
    }

    return cnt;
}
