struct node {
    int val;
    struct node *next;
};

typedef struct {
    struct node *head;
    size_t len;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList *obj = malloc(sizeof(*obj));
    if (obj == NULL) { return NULL; }
    obj->head = NULL;
    obj->len = 0;
    return obj;
}

int myLinkedListGet(MyLinkedList* obj, const int index) {
    if (index < 0 || (size_t)index >= obj->len) {
        return -1;
    }
    struct node *curr = obj->head;
    for (int steps = 0; steps < index; steps += 1) {
        curr = curr->next;
    }
    return curr->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, const int val) {
    struct node *node = malloc(sizeof(*node));
    if (node == NULL) { exit(1); }
    node->val = val;
    node->next = obj->head;
    obj->head = node;
    obj->len += 1;
    struct node*curr = obj->head;
}

void myLinkedListAddAtTail(MyLinkedList* obj, const int val) {
    if (obj->len == 0) { return myLinkedListAddAtHead(obj, val); }

    struct node *node = malloc(sizeof(*node));
    if (node == NULL) { exit(1); }
    node->val = val;
    node->next = NULL;

    struct node *curr = obj->head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = node;
    obj->len += 1;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, const int index, const int val) {
    if (index < 0 || (size_t)index > obj->len) { return; }
    if (index == 0) { return myLinkedListAddAtHead(obj, val); }
    if (obj->len == (size_t)index) { return myLinkedListAddAtTail(obj, val); }

    struct node *node = malloc(sizeof(*node));
    if (node == NULL) { exit(1); }
    node->val = val;

    struct node *curr = obj->head;
    for (int steps = 0; steps + 1 < index; steps += 1) {
        curr = curr->next;
    }

    node->next = curr->next;
    curr->next = node;
    obj->len += 1;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || (size_t)index >= obj->len) { return; }

    if (index == 0) { 
        struct node *node = obj->head;
        obj->head = node->next;
        free(node);
        obj->len -= 1;
    } else {
        struct node *curr = obj->head;
        for (int steps = 0; steps + 1 < index; steps += 1) {
            curr = curr->next;
        }
        struct node *node = curr->next;
        curr->next = node->next;
        free(node);
        obj->len -= 1;
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    if (obj == NULL) { return; }
    struct node *curr = obj->head;
    obj->head = NULL;
    obj->len = 0;
    free(obj);
    while (curr != NULL) {
        struct node *next = curr->next;
        free(curr);
        curr = next;
    }
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/
