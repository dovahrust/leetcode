static inline int abs_int(const int a)
{
    return a < 0 ? -a : a;
}

static inline size_t max_usize(const size_t a, const size_t b)
{
    return a > b ? a : b;
}

int equalSubstring(const char* s, const char* t, const int max_cost)
{
    assert(s != NULL && t != NULL && max_cost >= 0);
    size_t lo = 0;
    size_t hi = 0;
    size_t res = 0;
    int cost = 0;

    while (s[hi] != '\0') {
        cost += abs_int((int)s[hi] - (int)t[hi]);
        while (cost > max_cost) {
            cost -= abs_int((int)s[lo] - (int)t[lo]);
            lo += 1;
        }
        res = max_usize(res, hi + 1 - lo);
        hi += 1;
    }

    assert(t[hi] == '\0' && res <= (size_t)INT_MAX);

    return (int)res;
}
