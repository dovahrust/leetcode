int minCost(
    const int *start_pos, int start_len,
    const int *home_pos, int home_len,
    const int *row_costs, int rows_len,
    const int *col_costs, int cols_len
) {
    int cost = 0;
    int x = start_pos[0];
    int y = start_pos[1];
    int hx = home_pos[0];
    int hy = home_pos[1];

    while (x != hx) {
        x += (x < hx ? 1 : -1);
        cost += row_costs[x];
    }

    while (y != hy) {
        y += (y < hy ? 1 : -1);
        cost += col_costs[y];
    }

    return cost;
}
