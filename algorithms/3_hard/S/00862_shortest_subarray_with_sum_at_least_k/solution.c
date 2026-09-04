#define INF INT_MAX

struct pair {
    int idx;
    int64_t sum;
};

int shortestSubarray(const int *restrict nums, const int len, const int k) {
    if (k <= 0 || len <= 0 || nums == NULL) { return -1; }

    int res = INF;
    int64_t sum = 0;
    struct pair *restrict q = malloc(((size_t)len + 1) * sizeof(*q));
    if (q == NULL) { return -1; }
    q[0] = (struct pair){ .idx = -1, .sum = 0 };
    size_t q_head = 0;
    size_t q_len = 1;

    for (int i = 0; i < len; i += 1) {
        sum += nums[i];

        while (q_len > 0 && q[q_head + q_len - 1].sum >= sum) {
            q_len -= 1;
        }

        while (q_len > 0 && sum - q[q_head].sum >= k) {
            res = MIN(res, i - q[q_head].idx);
            q_len -= 1;
            q_head += 1;
        }

        q[q_head + q_len] = (struct pair){ .idx = i, .sum = sum};
        q_len += 1;
    }

    free(q);
    if (res == INF) {
        return -1;
    }
    return res;
}
