#define MOD 1000000007

struct pair {
    int64_t max;
    int64_t min;
};

int maxProductPath(int *restrict *restrict grid, int rows, const int *restrict cols_data) {
    assert(rows > 0 && cols_data != NULL && cols_data[0] > 0 && grid != NULL);
    const int cols = cols_data[0];
    struct pair *buff = malloc(2 * (size_t)cols * sizeof(*buff));
    assert(buff != NULL);
    struct pair *restrict prev = &buff[0];
    struct pair *restrict curr = &buff[cols];

    prev[0] = (struct pair){ .max = grid[0][0], .min = grid[0][0] };
    for (int j = 1; j < cols; j += 1) {
        const int64_t v = prev[j - 1].min * grid[0][j];
        prev[j] = (struct pair){ .max = v, .min = v };
    }

    for (int i = 1; i < rows; i += 1) {
        const int64_t v = prev[0].min * grid[i][0];
        curr[0] = (struct pair){ .max = v, .min = v };

        for (int j = 1; j < cols; j += 1) {
            const int64_t cell = grid[i][j];
            const int64_t a = prev[j].min * cell;
            const int64_t b = prev[j].max * cell;
            const int64_t c = curr[j - 1].min * cell;
            const int64_t d = curr[j - 1].max * cell;

            curr[j] =  (struct pair){ .max = MAX(MAX(a, b), MAX(c, d)), .min = MIN(MIN(a, b), MIN(c, d)) };
        }
        struct pair *restrict temp = prev;
        prev = curr;
        curr = temp;
    }

    int res = 0;
    if (prev[cols - 1].max < 0) {
        res = -1;
    } else {
        res = (int)(prev[cols - 1].max % MOD);
    }

    free(buff);
    return res;
}
