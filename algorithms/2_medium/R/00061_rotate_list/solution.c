struct pair {
    struct ListNode *h1;
    struct ListNode *h2;
};

inline static int calc_len(struct ListNode *head) {
    int len = 0;
    while (head != NULL) {
        len += 1;
        head = head->next;
    }
    return len;
}

inline static struct pair split_into_two_list(struct ListNode *head, const int shift_cnt) {
    struct ListNode *curr = head;

    for (int i = 0; i < shift_cnt - 1; i += 1) {
        curr = curr->next;
    }

    struct ListNode *head2 = curr->next;
    curr->next = NULL;

    return (struct pair){ .h1 = head, .h2 = head2 };
}
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    const int len = calc_len(head);
    if (len <= 1) { return head; }
    const int shift_cnt = (len - (k % len)) % len;
    if (shift_cnt == 0) { return head; }

    struct pair p = split_into_two_list(head, shift_cnt);
    struct ListNode *curr = p.h2;

    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = p.h1;

    return p.h2;
}
