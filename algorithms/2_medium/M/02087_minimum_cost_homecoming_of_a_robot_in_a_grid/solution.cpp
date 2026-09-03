class Solution {
public:
    static int minCost(
        const vector<int>& start_pos,
        const vector<int>& home_pos,
        const vector<int>& row_costs,
        const vector<int>& col_costs
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
};
