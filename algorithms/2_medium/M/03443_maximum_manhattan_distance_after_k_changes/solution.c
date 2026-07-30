static inline int max_int(const int a, const int b)
{
    return a > b ? a : b;
}

struct data {
    int curr;
    char a;
    char b;
    int k;
};

static inline struct data data_init(const char a, const char b, const int k)
{
    return (struct data){ .curr = 0, .a = a, .b = b, .k = k };
}

__attribute__((no_sanitize("all")))
static inline void data_add(struct data* obj, const char ch)
{
    if (ch == obj->a || ch == obj->b) {
        obj->curr += 1;
    } else if (obj->k > 0) {
        obj->k -= 1;
        obj->curr += 1;
    } else {
        obj->curr -= 1;
    }
}

__attribute__((no_sanitize("all")))
int maxDistance(const char* s, const int k)
{
    if (s == NULL) { return 0; }
    int max = 0;
    struct data ne = data_init('N', 'E', k);
    struct data nw = data_init('N', 'W', k);
    struct data se = data_init('S', 'E', k);
    struct data sw = data_init('S', 'W', k);

    for (const char* it = s; *it != '\0'; it += 1) {
        assert(it - s <= 100000);

        data_add(&ne, *it);
        data_add(&nw, *it);
        data_add(&se, *it);
        data_add(&sw, *it);

        max = max_int(max, ne.curr);
        max = max_int(max, nw.curr);
        max = max_int(max, se.curr);
        max = max_int(max, sw.curr);
    }

    return max;
}
