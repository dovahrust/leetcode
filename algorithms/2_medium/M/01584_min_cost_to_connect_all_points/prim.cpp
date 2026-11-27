class Solution {
public:
    static int minCostConnectPoints(const vector<vector<int>>& points) {
        const size_t n = points.size();
        auto in_tree = vector<char>(n, 0);
        auto min_dist = vector<int>(n, numeric_limits<int>::max());
        min_dist[0] = 0;
        int cost = 0;

        for (size_t step = 0; step < n; step += 1) {
            size_t u = numeric_limits<size_t>::max();
            int best = numeric_limits<int>::max();

            for (size_t v = 0; v < n; v += 1) {
                if (in_tree[v] == 0 && min_dist[v] < best) {
                    u = v;
                    best = min_dist[v];
                }
            }

            cost += best;
            in_tree[u] = 1;
            const int ux = points[u][0];
            const int uy = points[u][1];

            for (size_t v = 0; v < n; v += 1) {
                if (!in_tree[v]) {
                    const int d = std::abs(ux - points[v][0]) + std::abs(uy - points[v][1]);

                    min_dist[v] = std::min(min_dist[v], d);
                }
            }
        }

        return cost;
    }
};
