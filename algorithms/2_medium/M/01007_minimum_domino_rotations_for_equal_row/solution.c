#define INF INT_MAX

inline static size_t calc(const int val, const int len, const int *tops, const int *bottoms) {
    int need_top = 0;
    int need_bottom = 0;
    for (int i = 0; i < len; i += 1) {
        if (tops[i] != val && bottoms[i] != val) {
            return INF;
        }

        if (tops[i] != val) {
            need_top += 1;
        }

        if (bottoms[i] != val) {
            need_bottom += 1;
        }
    }

    return MIN(need_top, need_bottom);
}

int minDominoRotations(int* tops, int tops_len, int* bottoms, int bottoms_len) {
    assert(tops_len > 0 && tops_len == bottoms_len && tops != NULL && bottoms != NULL);

    const int cost_top_first = calc(tops[0], tops_len, tops, bottoms);
    const int cost_bottom_first = calc(bottoms[0], tops_len, tops, bottoms);

    if (cost_top_first == INF && cost_bottom_first == INF) {
        return -1;
    }

    return MIN(cost_top_first, cost_bottom_first);
}
