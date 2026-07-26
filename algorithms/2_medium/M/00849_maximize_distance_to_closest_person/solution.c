static inline int max_int(const int a, const int b)
{
    return a > b ? a : b;
}

static inline bool any_of(const int* arr, const int len, const int val)
{
    for (int i = 0; i < len; i += 1) {
        if (arr[i] == val) {
            return true;
        }
    }
    return false;
}

int maxDistToClosest(const int* seats, const int len)
{
    assert(len > 0 && seats != NULL);
    assert(any_of(seats, len, 0));
    assert(any_of(seats, len, 0));

    int prev = -1;
    int res = 0;
    for (int i = 0; i < len; i += 1) {
        assert(seats[i] == 0 || seats[i] == 1);

        if (seats[i] == 1) {
            switch (prev) {
                case -1:
                    res = i;
                    break;
                default:
                    res = max_int(res, (i - prev) / 2);
                    break;
            }

            prev = i;
        }
    }
    res = max_int(res, len - 1 - prev);

    return res;
}
