/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


typedef struct {
    struct ListNode *head;
} Solution;


Solution* solutionCreate(struct ListNode* head) {
    Solution* obj = malloc(sizeof(*obj));
    if (obj == NULL) {
        fprintf(stderr, "alloc fail");
        return NULL;
    }
    obj->head = head;
    return obj;
}

int solutionGetRandom(Solution* obj) {
    int64_t i = 1;
    int res = 0;
    struct ListNode *curr = obj->head;
    while (curr != NULL) {
        if (random() % i == 0) {
            res = curr->val;
        }
        curr = curr->next;
        i += 1;
    }
    return res;
}

void solutionFree(Solution* obj) {
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(head);
 * int param_1 = solutionGetRandom(obj);
 
 * solutionFree(obj);
*/
