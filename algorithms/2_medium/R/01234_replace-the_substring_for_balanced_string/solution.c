static inline size_t get_idx(const char ch)
{
    switch (ch) {
        case 'Q':
            return 0;
        case 'W':
            return 1;
        case 'E':
            return 2;
        case 'R':
            return 3;
        default:
            fprintf(stderr, "unreachable!(): invalid input");
            exit(1);
    }
}

int balancedString(const char* s)
{
    const size_t len = strlen(s);
    assert(len % 4 == 0 && len != 0 && len <= 100000);
    int cnt[4] = { 0 };
    for (size_t i = 0; i < len; i += 1) {
        cnt[get_idx(s[i])] += 1;
    }
    size_t lo = 0;
    const int limit = (int)(len / 4);
    size_t res = len;

    for (size_t hi = 0; hi < len; hi +=1) {
        cnt[get_idx(s[hi])] -= 1;
        while (lo <= hi && cnt[get_idx(s[lo])] < limit) {
            cnt[get_idx(s[lo])] += 1;
            lo += 1;
        }

        if (cnt[0] <= limit && cnt[1] <= limit && cnt[2] <= limit && cnt[3] <= limit) {
            if (hi + 1 - lo < res) {
                res = hi + 1 - lo;
            }
        }
    }

    return (int)res;
}
