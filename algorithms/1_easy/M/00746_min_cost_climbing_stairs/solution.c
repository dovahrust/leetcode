int minCostClimbingStairs(const int *restrict cost, const int len) {
    int prev = 0;
    int prev_prev = 0;

    for (int i = 0; i < len; i += 1) {
        const int curr = cost[i] + MIN(prev, prev_prev);
        prev_prev = prev;
        prev = curr;
    }

    return MIN(prev, prev_prev);
}
