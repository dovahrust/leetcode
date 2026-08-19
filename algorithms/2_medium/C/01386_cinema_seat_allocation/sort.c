#define LEFT 0b000011110
#define RIGHT 0b111100000
#define MID 0b001111000

static int cmp(const void *a_ptr, const void *b_ptr) {
    const int *a = *(const int **)a_ptr;
    const int *b = *(const int **)b_ptr;

    if (a[0] == b[0]) {
        return (a[1] > b[1]) - (a[1] < b[1]);
    } else {
        return (a[0] > b[0]) - (a[0] < b[0]);
    }
}

int maxNumberOfFamilies(const int n, int *restrict *restrict reserved_seats, const int len, const int *restrict cols_data) {
    assert(len <= 10000 && n >= 1 && n <= 1000000000);

    qsort(reserved_seats, (size_t)len, sizeof(*reserved_seats), cmp);

    int prev_row = 0;
    int res = 0;
    int idx = 0;

    while (idx < len) {
        const int curr_row = reserved_seats[idx][0];
        res += (curr_row - 1 - prev_row) * 2;

        uint32_t seen = 0;
        while (idx < len && reserved_seats[idx][0] == curr_row) {
            assert(reserved_seats[idx][1] >= 1 && reserved_seats[idx][1] <= 10);
            const uint32_t curr_col = (uint32_t)reserved_seats[idx][1];
            const uint32_t mask = (1u << (curr_col - 1));
            seen |= mask;
            idx += 1;
        }

        if ((seen & LEFT) == 0 && (seen & RIGHT) == 0) {
            res += 2;
        } else if ((seen & LEFT) == 0 || (seen & RIGHT) == 0 || (seen & MID) == 0) {
            res += 1;
        }

        prev_row = curr_row;
    }
    res += (n - prev_row) * 2;

    return res;
}
