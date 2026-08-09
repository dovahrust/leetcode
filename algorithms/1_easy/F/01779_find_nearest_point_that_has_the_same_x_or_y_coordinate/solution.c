#define INF INT_MAX

static inline int abs_int(const int a) {
    return a < 0 ? -a : a;
}

int nearestValidPoint(const int x, const int y, int** points, const int rows, const int *restrict cols_data) {
    assert(rows > 0 && cols_data != NULL && points != NULL);
    assert(x >= 1 && x <= 10000 && y >= 1 && y <= 10000);
    int min_dis = INF;
    int min_dis_idx = -1;

    for (int i = 0; i < rows; i += 1) {
        assert(cols_data[i] == 2);
        const int px = points[i][0];
        const int py = points[i][1];
        assert(px >= 1 && px <= 10000 && py >= 1 && py <= 10000);
        if (px == x || py == y) {
            const int curr_dis = abs_int(x - px) + abs_int(y - py);
            if (curr_dis < min_dis) {
                min_dis = curr_dis;
                min_dis_idx = i;
            }
        }
    }

    return min_dis_idx;
}
