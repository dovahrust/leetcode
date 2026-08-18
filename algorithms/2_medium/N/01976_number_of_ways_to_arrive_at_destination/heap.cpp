constexpr int64_t MOD = 1'000'000'007;

class Solution {
    struct Cmp {
        bool operator()(const pair<int64_t, int64_t>& a, const pair<int64_t, int64_t>& b) {
            return a.first > b.first;
        }
    };
public:
    static int countPaths(const int n, const vector<vector<int>>& roads) {
        assert(n > 0 && n <= 200);
        auto adj = vector<vector<pair<int, int>>>(n, vector<pair<int, int>>());
        for (const auto& r : roads) {
            assert(r.size() == 3);
            const int u = r[0];
            const int v = r[1];
            const int w = r[2];
            assert(u >= 0 && u < n && v >= 0 && v < n && w >= 1);
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        auto heap = priority_queue<
            pair<int64_t, int64_t>,
            vector<pair<int64_t, int64_t>>,
            Cmp
        >();
        auto costs = vector<pair<int64_t, int64_t>>(n, { numeric_limits<int64_t>::max(), 0 });
        heap.push({0, 0});
        costs[0] = {0, 1};

        while (!heap.empty()) {
            const auto [cost, u] = heap.top();
            heap.pop();
            if (cost > costs[u].first) { continue; }

            const int64_t ways = costs[u].second;

            for (const auto [v, w] : adj[u]) {
                const int64_t new_cost = cost + w;
                if (new_cost < costs[v].first) {
                    costs[v].first = new_cost;
                    costs[v].second = ways;
                    heap.push({new_cost, v});
                } else if (new_cost == costs[v].first) {
                    costs[v].second = (costs[v].second + ways) % MOD;
                }
            }
        }

        return static_cast<int>(costs[(n - 1)].second);
    }
};
