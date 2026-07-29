static inline int max_int(const int a, const int b)
{
    return a > b ? a : b;
}

struct deque {
    size_t cap;
    size_t len;
    size_t head;
    int ptr[];
};

static inline struct deque* deque_init(const size_t len)
{
    struct deque* init = malloc(len * sizeof(int) + sizeof(*init));
    assert(init != NULL);
    init->cap = 0;
    init->len = 0;
    init->head = 0;
    return init;
}

int longestSubarray(const int* nums, const int len, const int limit)
{
    assert(len > 0 && nums != NULL && limit >= 0);
    struct deque* minq = deque_init((size_t)len);
    struct deque* maxq = deque_init((size_t)len);
    int lo = 0;
    int res = 0;

    for (int hi = 0; hi < len; hi += 1) {
        const int num = nums[hi];
        while (maxq->head < maxq->len && maxq->ptr[maxq->len - 1] < num) {
            maxq->len -= 1;
        }
        while (minq->head < minq->len && minq->ptr[minq->len - 1] > num) {
            minq->len -= 1;
        }
        maxq->ptr[maxq->len] = num;
        maxq->len += 1;
        minq->ptr[minq->len] = num;
        minq->len += 1;

        while (limit < maxq->ptr[maxq->head] - minq->ptr[minq->head]) {
            if (maxq->ptr[maxq->head] == nums[lo]) {
                maxq->head += 1;
            }
            if (minq->ptr[minq->head] == nums[lo]) {
                minq->head += 1;
            }
            lo += 1;
        }

        res = max_int(res, hi - lo + 1);
    }

    return res;
}
