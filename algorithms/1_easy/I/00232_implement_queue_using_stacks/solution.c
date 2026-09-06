struct vec {
    int *restrict ptr;
    size_t len;
    size_t cap;
};

static void vec_push(struct vec *restrict vec, const int val) {
    if (vec->cap == vec->len) {
        const size_t new_cap = vec->cap == 0 ? 4 : 2 * vec->cap;
        void *restrict ptr = realloc(vec->ptr, new_cap * sizeof(*vec->ptr));
        if (ptr == NULL) { exit(1); }
        vec->ptr = ptr;
        vec->cap = new_cap;
    }
    vec->ptr[vec->len] = val;
    vec->len += 1;
}

static int vec_pop(struct vec *restrict vec) {
    if (vec->len == 0) { exit(1); }
    vec->len -= 1;
    return vec->ptr[vec->len];
}

typedef struct {
    struct vec put_stack;
    struct vec get_stack;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* obj = malloc(sizeof(*obj));
    if (obj == NULL) { return NULL; }
    obj->put_stack.ptr = NULL;
    obj->put_stack.len = 0;
    obj->put_stack.cap = 0;

    obj->get_stack.ptr = NULL;
    obj->get_stack.len = 0;
    obj->get_stack.cap = 0;

    return obj;
}

static void fill_get_stack(MyQueue* obj) {
    if (obj->get_stack.len == 0) {
        while (obj->put_stack.len > 0) {
            vec_push(&obj->get_stack, vec_pop(&obj->put_stack));
        }
        obj->put_stack.len = 0;
    }
}

void myQueuePush(MyQueue* obj, int x) {
    vec_push(&obj->put_stack, x);
}

int myQueuePop(MyQueue* obj) {
    fill_get_stack(obj);
    if (obj->get_stack.len == 0) { exit(1); }
    obj->get_stack.len -= 1;
    return obj->get_stack.ptr[obj->get_stack.len];
}

int myQueuePeek(MyQueue* obj) {
    fill_get_stack(obj);
    if (obj->get_stack.len == 0) { exit(1); }
    return obj->get_stack.ptr[obj->get_stack.len - 1];
}

bool myQueueEmpty(MyQueue* obj) {
    return obj == NULL || (obj->get_stack.len == 0 && obj->put_stack.len == 0);
}

void myQueueFree(MyQueue* obj) {
    if (obj == NULL) { return; }

    free(obj->put_stack.ptr);
    free(obj->get_stack.ptr);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
