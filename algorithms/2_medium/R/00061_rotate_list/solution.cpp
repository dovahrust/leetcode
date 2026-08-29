/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    inline static int calc_len(struct ListNode *head) {
        int len = 0;
        while (head != NULL) {
            len += 1;
            head = head->next;
        }
        return len;
    }

    inline static pair<ListNode*, ListNode*> split_into_two_list(ListNode *head, int shift_cnt) {
        ListNode* curr = head;

        for (int i{ 0 }; i < shift_cnt - 1; i += 1) {
            curr = curr->next;
        }

        auto head2 = curr->next;
        curr->next = nullptr;

        return {head, head2};
    }
public:
    static ListNode *rotateRight(ListNode *head, const int k) {
        const int len = calc_len(head);
        if (len <= 1) { return head; }
        const int shift_cnt = (len - (k % len)) % len;
        if (shift_cnt == 0) { return head; }

        auto [h1, h2] = split_into_two_list(head, shift_cnt);
        ListNode* curr = h2;

        while (curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = h1;

        return h2;
    }
};
