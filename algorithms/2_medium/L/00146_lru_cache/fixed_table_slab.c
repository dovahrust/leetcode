#define MAX_KEY 10000
#define INVALID_IDX SIZE_MAX
#define TABLE_LEN (MAX_KEY + 1)

struct node {
    int key;
    int val;
    size_t next;
    size_t prev;
};

typedef struct {
    size_t cap;
    size_t len;
    size_t head;
    size_t tail;
    struct node *restrict ll;
    size_t *restrict table;
} LRUCache;

LRUCache* lRUCacheCreate(const int cap) {
    if (cap <= 0) { return NULL; }

    LRUCache* obj = malloc(sizeof(*obj));
    if (obj == NULL) { return NULL; }

    struct node *ll = malloc((size_t)cap * sizeof(*ll));
    if (ll == NULL) {
        free(obj);
        return NULL;
    }

    size_t *table = malloc(TABLE_LEN * sizeof(*table));
    if (table == NULL) {
        free(ll);
        free(obj);
        return NULL;
    }

    for (size_t i = 0; i < TABLE_LEN; i += 1) {
        table[i] = INVALID_IDX;
    }
    obj->table = table;
    obj->ll = ll;
    obj->head = INVALID_IDX;
    obj->tail = INVALID_IDX;
    obj->cap = (size_t)cap;
    obj->len = 0;
    return obj;
}

inline static void move_node_to_head(LRUCache *obj, const size_t node_idx) {
    if (node_idx == obj->head) { return; }

    const size_t prev_idx = obj->ll[node_idx].prev;
    const size_t next_idx = obj->ll[node_idx].next;

    obj->ll[node_idx].next = obj->head;
    obj->ll[node_idx].prev = INVALID_IDX;

    obj->ll[obj->head].prev = node_idx;
    obj->head = node_idx;

    obj->ll[prev_idx].next = next_idx;
    if (next_idx == INVALID_IDX) {
        obj->tail = prev_idx;
    } else {
        obj->ll[next_idx].prev = prev_idx;
    }
}

int lRUCacheGet(LRUCache* obj, int key) {
    if (key < 0 || key > MAX_KEY) { exit(1); }

    const size_t node_idx = obj->table[key];
    if (node_idx != INVALID_IDX) {
        move_node_to_head(obj, node_idx);
        return obj->ll[node_idx].val;
    }

    return -1;
}

void lRUCachePut(LRUCache* obj, const int key, const int val) {
    if (key < 0 || key > MAX_KEY) { exit(1); }

    if (obj->table[key] != INVALID_IDX) {
        const size_t node_idx = obj->table[key];
        obj->ll[node_idx].val = val;
        move_node_to_head(obj, node_idx);
    } else if (obj->len == obj->cap) {
        const size_t tail_idx = obj->tail;
        const size_t old_tail_key = obj->ll[tail_idx].key;
        obj->table[old_tail_key] = INVALID_IDX;
        obj->table[key] = tail_idx;
        obj->ll[tail_idx].val = val;
        obj->ll[tail_idx].key = key;
        move_node_to_head(obj, tail_idx);
    } else {
        const size_t new_node_idx = obj->len;
        obj->ll[obj->len] = (struct node){ .key = key, .val = val, .prev = INVALID_IDX, .next = obj->head };
        obj->len += 1;
        if (obj->head == INVALID_IDX) {
            obj->head = new_node_idx;
            obj->tail = new_node_idx;
        } else {
            obj->ll[obj->head].prev = new_node_idx;
            obj->head = new_node_idx;
        }

        obj->table[key] = new_node_idx;
    }
}

void lRUCacheFree(LRUCache* obj)
{
    if (obj == NULL) { return; }
    free(obj->ll);
    free(obj->table);
    free(obj);
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);

 * lRUCachePut(obj, key, value);

 * lRUCacheFree(obj);
*/
